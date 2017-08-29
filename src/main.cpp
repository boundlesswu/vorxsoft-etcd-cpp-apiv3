#include <iostream>
#include <memory>
#include <string>
#include <exception>
#include <stdexcept> 

#include <grpc++/grpc++.h>
#include "VS_MicroService.h"


using namespace std;
using namespace VorxSoft;
using namespace google::protobuf;


static std::string etcd_uri("http://192.168.20.251:2379");
static int watcher_called = 0;
bool deleted = false;


void printResponse(etcd::Response const & resp)
{
	++watcher_called;
	std::cout << "print response called" << std::endl;
	if (resp.error_code())
		std::cout << resp.error_code() << ": " << resp.error_message() << std::endl;
	else
	{
		std::cout << resp.action() << " " << resp.value().as_string() << std::endl;
		std::cout << "Previous value: " << resp.prev_value().as_string() << std::endl;
		if (resp.action() == "delete") {
			deleted = true;
		}
	}
	return;
}

void printResponse2(etcd::Response const & resp,void* f)
{
	++watcher_called;
	std::cout << "print response called" << std::endl;
	if (resp.error_code())
		std::cout << resp.error_code() << ": " << resp.error_message() << std::endl;
	else
	{
		std::cout << resp.action() << " " << resp.value().as_string() << std::endl;
		std::cout << "Previous value: " << resp.prev_value().as_string() << std::endl;
		if (resp.action() == "delete") {
			deleted = true;
		}
	}
	return;
}

class WatchTest {
public:
	WatchTest() {
		//target_ = ""; pwatch_ = NULL;
	}
	~WatchTest() {}
	void SetWatchTest(std::string target, std::string key, std::function<void(Response)> callback) {
		target_ = target;
		pwatch_ =  new etcd::Watcher(target, key, callback);
	}
private:
	std::string target_;
	etcd::Watcher* pwatch_;
};

int main()
{
	std::string servicename("wwmTEST");
	std::string host("192.168.2.222");
	int port = 2222;
	google::protobuf::int64 ttl = 10;



	//etcd::Watcher watcher(etcd_uri, "/test", printResponse);
	//Sleep(1000000);
	//watcher.Cancel();
	//etcd.set("/test/key", "43"); /* print response will NOT be called, since watch is already cancelled */

#if 1
	void* p1=NULL;
	VS_MicroServiceWatcher test;
	//test.SetWatcher(etcd_uri, "/test", printResponse);
	test.SetWatcher2(etcd_uri,"vms", "/test/192.168.10.123:100", printResponse2,p1);
	Sleep(1000000);
#else
	VS_MicroService vag_service;
	//vag_service.SetWatcher(etcd_uri, "/test", printResponse);
	vag_service.SetWatcher(etcd_uri,"/test", printResponse);
	Sleep(1000000);
#endif

	//服务初始化
	//VS_MicroService vag_service(servicename,host,port,etcd_uri,ttl);

	//服务注册
	/*int ret = vag_service.Registe();
	if (ret < 0) {
	std::cout << "register to " << etcd_uri << "error" << std::endl;
	return -1;
	}
	else {
	std::cout << "success register to " << etcd_uri << std::endl;
	}*/
	//新建心跳线程
	//vag_service.NewAutoHeartBeatThread(ttl);
	//std::string serviceaddress;
	//vag_service.SetWatcher(printResponse);
	//do {
	//	Sleep((ttl-1) * 1000);

	//	serviceaddress = vag_service.Reslove(servicename, VorxSoft::VS_MicroService::ROUND);
	//	if (!serviceaddress.empty())
	//		cout << "resolve vag service address is " << vag_service.Reslove(servicename, VorxSoft::VS_MicroService::ROUND) << endl;
	//	else
	//		cout << "resolve vag service error,and not vag service address found!" << endl;

	//} while (1);
	return 0;
}


