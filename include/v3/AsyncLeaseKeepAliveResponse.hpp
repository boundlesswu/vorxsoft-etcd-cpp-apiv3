#ifndef __ASYNC_LEASEKEEPALIVERESPONSE_HPP__
#define __ASYNC_LEASEKEEPALIVERESPONSE_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "proto/rpc.pb.h"
#include "v3/V3Response.hpp"


using etcdserverpb::LeaseKeepAliveRequest;
using etcdserverpb::LeaseKeepAliveResponse;
using etcdserverpb::KV;

namespace etcdv3
{
  class AsyncLeaseKeepAliveResponse : public etcdv3::V3Response
  {
    public:
      AsyncLeaseKeepAliveResponse(){};
      void ParseResponse(LeaseKeepAliveResponse& resp);
  };
}

#endif

