#include <iostream>

#include "v3/AsyncLeaseKeepAliveResponse.hpp"
#include "v3/action_constants.hpp"

using namespace std;
void etcdv3::AsyncLeaseKeepAliveResponse::ParseResponse(LeaseKeepAliveResponse& reply)
{
	//std::cout << "lease id:" << reply.id() ;
	//std::cout << ",ttl:" << reply.ttl() ;
	//std::cout << ",response info " ;
	//std::cout << ",cluster_id:" << reply.header().cluster_id() ;
	//std::cout << ",member_id:" << reply.header().member_id() ;
	//std::cout << ",revision:" << reply.header().revision() ;
	//std::cout << ",raft term:" << reply.header().raft_term() << endl;
	index = reply.header().revision();
	value.kvs.set_lease(reply.id());
	value.set_ttl(reply.ttl());
	//error_message = reply.error();
	return;
}
