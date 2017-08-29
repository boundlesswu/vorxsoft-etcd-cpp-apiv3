/******************************************************************/
/** 文件名:VS_MicroService.cpp
** 版权：蛙视软件技术有限公司
** 创建人:吴文茂
** 日 期:2017-06-16
** 修改人:吴文茂
** 日 期:2017-07-05
** 描 述:蛙视软件微服务注册和发现模块类实现
** 版 本:0.2
**/
/******************************************************************/

#include <string.h>
#include "VS_MicroService.h"

VorxSoft::VS_MicroService::VS_MicroService()
{
	port_ = 0;
	pclient_ = NULL;
	pwatch_ = NULL;
	ttl_ = 0;
	policy_ = RANDOM;
}

VorxSoft::VS_MicroService::VS_MicroService(std::string target)
{
	port_ = 0;
	pclient_ = NULL;
	pwatch_ = NULL;
	ttl_ = 0;
	policy_ = RANDOM;
	pclient_ = new etcd::Client(target);
}

int VorxSoft::VS_MicroService::CreateLease()
{
	return CreateLease(ttl_, pclient_);
}

int VorxSoft::VS_MicroService::CreateLease(::google::protobuf::int64 ttl)
{
	return CreateLease(ttl, pclient_);
}

int VorxSoft::VS_MicroService::CreateLease(::google::protobuf::int64 ttl, etcd::Client* pclient)
{
	etcd::Response response = pclient->leasegrant(ttl).get();
	if (response.is_ok()) {
		std::cout << "The lease is successfully grant, leaseId is " << response.value().lease()<< std::endl;
		leaseId_ = response.value().lease();
		return 0;
	}
	else {
		std::cout << "operation failed, details: " << response.error_message();
		return -1;
	}
}

VorxSoft::VS_MicroService::VS_MicroService(std::string name, std::string host, int port, std::string target, ::google::protobuf::int64 ttl)
{
	port_ = 0;
	pclient_ = NULL;
	pwatch_ = NULL;
	ttl_ = 0;
	policy_ = RANDOM;
	name_ = name;
	host_ = host;
	port_ = port;
	pclient_ = new etcd::Client(target);
	ttl_ = ttl;
	CreateLease();
}

VorxSoft::VS_MicroService::~VS_MicroService()
{
	delete pwatch_;
	pwatch_ = NULL;
	delete pclient_;
	pclient_ = NULL;
}

int VorxSoft::VS_MicroService::Registe()
{
	return VorxSoft::VS_MicroService::Registe(name_,host_,port_);
}

int VorxSoft::VS_MicroService::Registe(string name, string host, int port)
{
	//time_t ctime = time(&ctime);
	time_t ctime = getTimeStamp();
	std::string value = std::to_string(ctime);
	return RegisteWithValue(name, host, port, value);
}

int VorxSoft::VS_MicroService::RegisteWithValue(string name, string host, int port, std::string value)
{
	std::string key = VS_MicroServicePath + "/" + name + "/" + host + ":" + std::to_string(port);
	etcd::Response response = pclient_->set(key, value, leaseId_).get();
	if (response.is_ok()) {
		std::cout << "key: "<< key << " value: "<< value << std::endl;
		std::cout << "The new value is successfully set, previous value was "<< response.prev_value().as_string() << std::endl;
		leaseId_ = response.value().lease();
		return 0;
	}
	else {
		std::cout << "operation failed, details: " << response.error_message() << std::endl;
		return -1;
	}
}

void VorxSoft::VS_MicroService::TimerThread(int ttl)
{
	while (true)
	{
		Sleep((ttl-1) * 1000);
		SendHeartBeat();
	}
	return;
}

void VorxSoft::VS_MicroService::NewAutoHeartBeatThread(int ttl)
{
	boost::function0<void> f = boost::bind(&VorxSoft::VS_MicroService::TimerThread, this, ttl);
	boost::thread thrd(f);
	thrd.detach();
	//thrd.join();
}

void VorxSoft::VS_MicroService::AutoHeartBeat(const boost::system::error_code& e, boost::asio::deadline_timer* t, int ttl,void* ptr)
{
	VorxSoft::VS_MicroService* ptr1 = (VorxSoft::VS_MicroService*) ptr;
	//cout <<"thread id is: "<< boost::this_thread::get_id() << " parant thread id is : "<< boost::this_thread::getendl;
		std::cout << time(NULL) << std::endl;
		ptr1->SendHeartBeat();
		t->expires_at(t->expires_at() + boost::posix_time::seconds(ttl - 1));
		t->async_wait(boost::bind(AutoHeartBeat, boost::asio::placeholders::error, t, ttl, ptr1));

}

void VorxSoft::VS_MicroService::SetAutoHeartBeat(int ttl)
{
	SendHeartBeat();
	boost::asio::io_service io;
	//boost::asio::io_service::work work(io);
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(ttl-1));
	t.async_wait(boost::bind(AutoHeartBeat, boost::asio::placeholders::error, &t, ttl,this));
	//boost::thread th(boost::bind(&boost::asio::io_service::run, &io));
	io.poll();
	//io.run();
	//th.join();
}
void VorxSoft::VS_MicroService::SetAutoHeartBeat()
{
	return SetAutoHeartBeat(ttl_);
}

int VorxSoft::VS_MicroService::SendHeartBeat()
{
	return SendHeartBeat(leaseId_);
}

int VorxSoft::VS_MicroService::SendHeartBeat(::google::protobuf::int64 id)
{
	etcd::Response const  response = pclient_->leasekeepalive(id).get();
	if (response.is_ok())
	{
		//std::cout << "lease id is " << response.value().lease() << "     ttl is " << response.value().ttl() << endl;
		return 0;
	}
	else
	{
		std::cout << response.error_code() << " " << response.error_message() << std::endl;
		return -1;
	}
	return 0;
}

int VorxSoft::VS_MicroService::UnRegiste()
{
	return UnRegiste(name_,host_,port_);
}

int VorxSoft::VS_MicroService::UnRegiste(std::string name, std::string host, int port)
{
	//std::string key = "/service/" + name + "/" + host + ":" + std::to_string(port);
	std::string key = VS_MicroServicePath +"/" + name + "/" + host + ":" + std::to_string(port);
	etcd::Response response = pclient_->rm(key).get();
	if (response.is_ok()) {
		std::cout << "The value is successfully rm, previous value was "
			<< response.prev_value().as_string() << std::endl;
		return 0;
	}
	else {
		std::cout << "operation failed, details: " << response.error_message() << std::endl;
		return -1;
	}
	return 0;
}

std::string VorxSoft::VS_MicroService::Reslove() 
{
	//std::string servicename = "/service/" + name_+"/";
	std::string servicename= VS_MicroServicePath + "/" + name_+"/";
	int len = servicename.length();
	vector<string> serviceurlarray;
	etcd::Response response = pclient_->ls(servicename).get();
	if (response.keys().size() == 0)
		return std::string("");
	for (int i = 0; i < response.keys().size(); i++)
	{
		//response.keys()[i].substr(len, response.keys()[i].length());
		serviceurlarray.push_back(response.keys()[i].substr(len, response.keys()[i].length()-len));
    	//std::cout << "NO" << i + 1 << " key:" << "\"" << response.keys()[i] << "\"" << " value";
		//std::cout << " = " << response.value(i).as_string() << std::endl;
	}
	srand((unsigned)time(NULL));
	switch (policy_)
	{
	case ROUND:
		return serviceurlarray.at(0);
	case RANDOM:
		return serviceurlarray.at(rand() % serviceurlarray.size());
	case	PERFORMANECE:
		//todo
	default:
		return serviceurlarray.at(rand() % serviceurlarray.size());
	}

}

std::string VorxSoft::VS_MicroService::Reslove(std::string name)
{
	name_ = name;
	return Reslove();
}

std::string VorxSoft::VS_MicroService::Reslove(std::string name, PolicyType policy)
{
	policy_ = policy;
	return Reslove(name);
}

void VorxSoft::VS_MicroService::SetWatcher(std::string key, std::function<void(Response)> callback)
{
	//pwatch_ = new etcd::Watcher(target_, key, callback);
	etcd::Watcher(target_, key, callback);
	//return 0;
}
void VorxSoft::VS_MicroService::SetWatcher( std::function<void(Response)> callback)
{
	std::string key = VS_MicroServicePath + "/" + name_ + "/" + host_ + ":" + std::to_string(port_);
	//pwatch_ = new etcd::Watcher(target_, key, callback);
	etcd::Watcher(target_, key, callback);
	//return 0;
}
std::string VorxSoft::GetCurrentVersion() {
	return VorxSoft::version;
}

void VorxSoft::VS_MicroService::SetWatcher(std::string target, std::string key, std::function<void(Response)> callback)
{
	if (pclient_ != NULL) delete pclient_;

	//etcd::Watcher watcher(etcd_uri, "/test", printResponse);
	//Sleep(1000000);
	//watcher.Cancel();
	//std::string key = VS_MicroServicePath + "/" + name_ + "/" + host_ + ":" + std::to_string(port_);
	etcd::Watcher watcher(target_, key, callback);
}

void VorxSoft::VS_MicroServiceWatcher::SetWatcher(std::string target, std::string key, std::function<void(Response)> callback) {
	target_ = target;
	key_ = key;
	pwatch_ = new etcd::Watcher(target, key, callback);
}

void VorxSoft::VS_MicroServiceWatcher::SetWatcher(std::string target, std::string name, std::string host, int port, std::function<void(Response)> callback) {
	std::string key = VS_MicroServicePath + "/" + name + "/" + host + ":" + std::to_string(port);
	SetWatcher(target, key, callback);
}

void VorxSoft::VS_MicroServiceWatcher::SetWatcher2(std::string target, std::string name, std::string ip, int port, watcher_callback f, void* ptr) {
	std::string key = VS_MicroServicePath + "/" + name + "/" + ip + ":" + std::to_string(port);
	SetWatcher2(target, key, f, ptr);
}
void VorxSoft::VS_MicroServiceWatcher::SetWatcher2(std::string target, std::string key, watcher_callback f, void* ptr) {
	pwatch_ = new etcd::Watcher(target, key, f, ptr);
}

void VorxSoft::VS_MicroServiceWatcher::SetWatcher2(std::string target, std::string name, std::string address, watcher_callback f, void* ptr) {
	std::string key = VS_MicroServicePath + "/" + name + "/"+ address;
	SetWatcher2(target, key, f, ptr);
	//pwatch_ = new etcd::Watcher(target, key, f,ptr);
}

void VorxSoft::VS_MicroServiceWatcher::delWatcher() {
	pwatch_->Cancel();
}

std::time_t VorxSoft::getTimeStamp()
{
	std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
	std::time_t timestamp = tmp.count();
	//std::time_t timestamp = std::chrono::system_clock::to_time_t(tp);  
	return timestamp;
}