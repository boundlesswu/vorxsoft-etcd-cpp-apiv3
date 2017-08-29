#include "v3/AsyncLeaseKeepAliveAction.hpp"
#include "v3/action_constants.hpp"


using etcdserverpb::RangeRequest;
using etcdserverpb::RangeResponse;
using etcdserverpb::LeaseKeepAliveRequest;

etcdv3::AsyncLeaseKeepAliveAction::AsyncLeaseKeepAliveAction(etcdv3::ActionParameters param)
  : etcdv3::Action(param) 
{
  isCancelled = false;
  stream = parameters.lease_stub->AsyncLeaseKeepAlive(&context, &cq_, (void*)"create");
  
  LeaseKeepAliveRequest request;
  request.set_id(parameters.lease_id);

  stream->Write(request, (void*)"write");
  stream->Read(&reply, (void*)this);
}


void etcdv3::AsyncLeaseKeepAliveAction::waitForResponse() 
{
  void* got_tag;
  bool ok = false;    
  
  while(cq_.Next(&got_tag, &ok))
  {
    if(ok == false || (got_tag == (void*)"writes done"))
    {
      break;
    }
    if(got_tag == (void*)this) // read tag
    {
	  if(reply.ByteSize())
      {
        stream->WritesDone((void*)"writes done");
      }
      else
      {
        stream->Read(&reply, (void*)this);
      } 
    }  
  }
}

void etcdv3::AsyncLeaseKeepAliveAction::CancelLeaseKeepAlive()
{
  if(isCancelled == false)
  {
    stream->WritesDone((void*)"writes done");
  }
}

void etcdv3::AsyncLeaseKeepAliveAction::waitForResponse(std::function<void(etcd::Response)> callback) 
{
  void* got_tag;
  bool ok = false;    

  while(cq_.Next(&got_tag, &ok))
  {
    if(ok == false)
    {
      break;
    }
    if(got_tag == (void*)"writes done")
    {
      isCancelled = true;
    }
    else if(got_tag == (void*)this) // read tag
    {
	  //etcd::Response resp(ParseResponse());
	  etcd::Response resp = ParseResponse();
	  callback(resp);

      stream->Read(&reply, (void*)this);
    }     
  }
}

etcdv3::AsyncLeaseKeepAliveResponse etcdv3::AsyncLeaseKeepAliveAction::ParseResponse()
{

  AsyncLeaseKeepAliveResponse resp;
  if(!status.ok())
  {
    resp.set_error_code(status.error_code());
    resp.set_error_message(status.error_message());
  }
  else
  { 
    resp.ParseResponse(reply);
  }
  return resp;
}
