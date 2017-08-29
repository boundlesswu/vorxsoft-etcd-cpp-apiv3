#ifndef __ASYNC_LEASEKEEPALIVEACTION_HPP__
#define __ASYNC_LEASEKEEPALIVEACTION_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/Action.hpp"
#include "v3/AsyncleaseKeepAliveResponse.hpp"
#include "etcd/Response.hpp"


using grpc::ClientAsyncReaderWriter;
using etcdserverpb::LeaseKeepAliveRequest;
using etcdserverpb::LeaseKeepAliveResponse;
using etcd::Response;


namespace etcdv3
{
  class AsyncLeaseKeepAliveAction : public etcdv3::Action
  {
    public:
      AsyncLeaseKeepAliveAction(etcdv3::ActionParameters param);
      AsyncLeaseKeepAliveResponse ParseResponse();
      void waitForResponse();
      void waitForResponse(std::function<void(etcd::Response)> callback); 
      void CancelLeaseKeepAlive();
      //void WatchReq(std::string const & key);
    private:
      LeaseKeepAliveResponse reply;
      std::unique_ptr<ClientAsyncReaderWriter<LeaseKeepAliveRequest,LeaseKeepAliveResponse>> stream;   
      bool isCancelled;
  };
}

#endif
