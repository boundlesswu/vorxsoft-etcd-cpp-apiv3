#ifndef __ASYNC_WATCHACTION_HPP__
#define __ASYNC_WATCHACTION_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/Action.hpp"
#include "v3/AsyncWatchResponse.hpp"
#include "etcd/Response.hpp"


using grpc::ClientAsyncReaderWriter;
using etcdserverpb::WatchRequest;
using etcdserverpb::WatchResponse;

typedef	void(__stdcall *watcher_callback)(etcd::Response const & resp, void* ptr);

namespace etcdv3
{
  class AsyncWatchAction : public etcdv3::Action
  {
    public:
      AsyncWatchAction(etcdv3::ActionParameters param);
      AsyncWatchResponse ParseResponse();
      void waitForResponse();
      void waitForResponse(std::function<void(etcd::Response)> callback); 
	  void waitForResponse(watcher_callback callback,void* ptr);
      void CancelWatch();
      void WatchReq(std::string const & key);
    private:
      WatchResponse reply;
      std::unique_ptr<ClientAsyncReaderWriter<WatchRequest,WatchResponse>> stream;   
      bool isCancelled;
  };
}

#endif
