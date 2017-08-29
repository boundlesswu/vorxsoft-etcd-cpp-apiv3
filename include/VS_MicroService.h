/******************************************************************/
/** 文件名:VS_MicroService.h
** 版权：蛙视软件技术有限公司
** 创建人:吴文茂
** 日 期:2017-06-16
** 修改人:吴文茂
** 日 期:2017-07-05
** 描 述:蛙视软件微服务注册和发现模块类头文件
** 版 本:0.2
**/
/******************************************************************/
#ifndef __VS_MICRO_SERVICE_H__
#define __VS_MICRO_SERVICE_H__

#include <string>
#include <vector>

#include <iostream>
//boost header
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/asio/high_resolution_timer.hpp>

#include "etcd/Client.hpp"
#include "etcd/Watcher.hpp"

using namespace std;
using namespace etcd;
//using namespace boost;
//using namespace boost::system;

//typedef	void(__stdcall *watcher_callback)(etcd::Response const & resp,void* ptr);

namespace VorxSoft{

	std::time_t getTimeStamp();

	const std::string VS_MicroServicePath = "/service";
	const std::string version = "4.0.0.1";
	/*****************************************************************/
	/** 函数名:GetVersion
	** 功能描述:获取当前库的版本号
	**参数:无
	**返回值：std::string
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	std::string GetCurrentVersion();

class VS_MicroService
{
public:
	enum PolicyType
	{
		ROUND = 1,
		RANDOM = 2,
		PERFORMANECE = 3
	};
	/*****************************************************************/
	/** 函数名:VS_MicroService
	** 功能描述:VS_MicroService默认构造函数，设置内部成员变量为默认值
	**参数:
	** 参数名 1 【I-输入/O-输出】参数说明
	** 参数名 2【I-输入/O-输出】参数说明
	**返回值：无
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	VS_MicroService();

	/*****************************************************************/
	/** 函数名:VS_MicroService
	** 功能描述:VS_MicroService构造函数，建立与注册中心的连接，成功后pclient_指针不为空
	**参数:
	** 参数名 target 【I-输入】注册中心地址 字符串类型 例如"http://192.168.20.251:2379"
	** 参数名 2【I-输入/O-输出】参数说明
	**返回值：无
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	VS_MicroService(std::string target);

	/*****************************************************************/
	/** 函数名:VS_MicroService
	** 功能描述:VS_MicroService构造函数，执行完毕后，与注册中心连接上，并将连接指针存放到pclient_中，其他相应的成员变量也以此赋值
	**参数:
	** 参数名 name 【I-输入】服务名称，字符串类型 例如"vag"
	** 参数名 host【I-输入】服务所在主机ip地址，字符串变量，比如"192.168.1.1"
	** 参数名 port 【I-输入】服务的端口号 整形变量 例如1234
	** 参数名 target 【I-输入】注册中心地址 字符串类型 例如"http://192.168.20.251:2379"
	** 参数名 ttl【I-输入】参数说明 整形变量 服务注册的老化时间 单位为秒
	**返回值：无
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	VS_MicroService::VS_MicroService(std::string name, std::string host, int port, std::string target, ::google::protobuf::int64 ttl);
	
	/*****************************************************************/
	/** 函数名:~VS_MicroService
	** 功能描述:VS_MicroService默认析构函数
	**参数:无
	** 参数名 1 【I-输入/O-输出】参数说明
	** 参数名 2【I-输入/O-输出】参数说明
	**返回值：无
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	~VS_MicroService();

	/*****************************************************************/
	/** 函数名:CreateLease
	** 功能描述:建立租约
	**参数:
	** 参数名 ttl 【I-输入】整形变量 服务注册的老化时间
	          pclient_ 【I-输入】 连接注册中心的指针
	**返回值：0：成功。-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	int VS_MicroService::CreateLease(::google::protobuf::int64 ttl, etcd::Client* pclient);

	/*****************************************************************/
	/** 函数名:CreateLease
	** 功能描述:建立租约
	**参数:
	** 参数名 ttl 【I-输入】服务注册的老化时间
	隐含参数,pclient_ 内部的连接注册中心的指针
	隐含参数必须在调用前以及初始化完成
	**返回值：0：成功。-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
		int VS_MicroService::CreateLease(::google::protobuf::int64 ttl);

	/*****************************************************************/
	/** 函数名:CreateLease
	** 功能描述:建立租约
	**参数:无
	隐含参数,ttl_ 内部的服务注册的老化时间
	pclient_ 内部的连接注册中心的指针
	隐含参数必须在调用前以及初始化完成
	**返回值：0：成功。-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	int VS_MicroService::CreateLease();

	/*****************************************************************/
	/** 函数名:Registe
	** 功能描述:在注册中心注册，注册成功后，在{VS_MicroServicePath}/{name_}路径下建立一个host_:port_的key，value为默认值，当前系统的时间戳
	**参数:无 
	    默认使用name_,host_和port_作为参数，
	    name_ 【I-输入】服务名称，字符串类型 例如"vag"
	    host_【I-输入】服务所在主机ip地址，字符串变量，比如"192.168.1.1"
	    port_ 【I-输入】服务的端口号 整形变量 例如1234
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	int Registe();

	/*****************************************************************/
	/** 函数名:Registe
	** 功能描述:在注册中心注册，注册成功后，在{VS_MicroServicePath}/{name}路径下建立一个host:port的key，value为默认值，当前系统的时间戳
	**参数:
	** 参数名 name 【I-输入】服务名称，字符串类型 例如"vag"
	** 参数名 host【I-输入】服务所在主机ip地址，字符串变量，比如"192.168.1.1"
	** 参数名 port 【I-输入】服务的端口号 整形变量 例如1234
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/

	int Registe(std::string name,std::string host, int port);
	/*****************************************************************/
	/** 函数名:RegisteWithValue
	** 功能描述:在注册中心注册，注册成功后，在{VS_MicroServicePath}/{name}路径下建立一个host:port的key，value为value
	**参数:
	** 参数名 name 【I-输入】服务名称，字符串类型 例如"vag"
	** 参数名 host【I-输入】服务所在主机ip地址，字符串变量，比如"192.168.1.1"
	** 参数名 port 【I-输入】服务的端口号 整形变量 例如1234
	** 参数名 value 【I-输入】注册所使用的value  字符串类型 例如"123456"
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	int RegisteWithValue(string name, string host, int port,  std::string value);

	/*****************************************************************/
	/** 函数名:SendHeartBeat
	** 功能描述:在注册中心注册成功并申请租约后，微服务向注册中心发送心跳消息，
	             防止注册的服务因为达到老化时间，而被注册中心删除
	**参数:无 隐形参数如下
	          ** 参数名 leaseId_ 成功注册后的服务的租约id，
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	int SendHeartBeat();
	/*****************************************************************/
	/** 函数名:SendHeartBeat
	** 功能描述:在注册中心注册成功并申请租约后，微服务向注册中心发送心跳消息，
	防止注册的服务因为达到老化时间，而被注册中心删除
	**参数:
	** 参数名 id 需要发送心跳消息的服务的租约id，
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	int SendHeartBeat(::google::protobuf::int64 id);

	/*****************************************************************/
	/** 函数名:UnRegiste
	** 功能描述:服务在注册中心解除注册
	**参数:无 隐形参数如下
	       ** 参数名 name_ 【I-输入】服务名称，类成员变量，在前面初始化完成
	       ** 参数名 host_【I-输入】服务所在主机ip地址，类成员变量，在前面初始化完成
	       ** 参数名 port_ 【I-输入】服务的端口号 类成员变量，在前面初始化完成
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	int UnRegiste();

	/*****************************************************************/
	/** 函数名:UnRegiste
	** 功能描述:服务在注册中心解除注册
	**参数:
	** 参数名 name 【I-输入】服务名称，字符串类型 例如"vag"
	** 参数名 host【I-输入】服务所在主机ip地址，字符串变量，比如"192.168.1.1"
	** 参数名 port 【I-输入】服务的端口号 整形变量 例如1234
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	int UnRegiste(std::string name, std::string host, int port);

	/*****************************************************************/
	/** 函数名:Reslove
	** 功能描述:在注册中心解析服务，获取服务地址，默认策略使用RANDOM策略
	**参数:无 默认参数为name_服务名称，字符串类型 例如"vag"
	**返回值：成功解析返回服务的地址字符串，比如"192.168.1.100:2000",失败返回空字符串""
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	std::string Reslove();

	/*****************************************************************/
	/** 函数名:Reslove
	** 功能描述:在注册中心解析服务，获取服务地址，默认策略使用RANDOM策略
	**参数:
	** 参数名 name 【I-输入】服务名称，字符串类型 例如"vag"
	**返回值：成功解析返回服务的地址字符串，比如"192.168.1.100:2000",失败返回空字符串""
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	std::string Reslove(std::string name);

	/*****************************************************************/
	/** 函数名:Reslove
	** 功能描述:在注册中心解析服务，获取服务地址
	**参数:
	** 参数名 name 【I-输入】服务名称，字符串类型 例如"vag"
	** 参数名 policy【I-输入】解析策略，枚举类型，ROUND、RANDOM 、PERFORMANECE 
	          三种类型默认是RANDOM，是环形策略，选择服务地址，RANDOM是随机策略，PERFORMANECE是按照最优性能选择服务地址
	**返回值：成功解析返回服务的地址字符串，比如"192.168.1.100:2000",失败返回空字符串""
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	std::string Reslove(std::string name, PolicyType policy);

	/*****************************************************************/
	/** 函数名:SetWatcher
	** 功能描述:设置服务监测以及服务变化后的回调
	**参数:
	** 参数名 key 【I-输入】需要监测的服务的key值，包含全路径，字符串类型 例如"/service/vag/192.168.1.100:2000"
	** 参数名 callback【I-输入】函数回调，设置成功后，key值发生变化后，调用回调函数
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	void SetWatcher(std::string key, std::function<void(Response)> callback);
	/*****************************************************************/
	/** 函数名:SetWatcher
	** 功能描述:设置服务监测以及服务变化后的回调
	**参数:
		** 参数名 callback【I-输入】函数回调，设置成功后，key值发生变化后，调用回调函数
		隐含参数 类的成员变量name_,host_、port_,由他们组成所要监控的key值
	**返回值：0：成功；-1：失败
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	void SetWatcher(std::function<void(Response)> callback);
	
	void SetAutoHeartBeat();

	/*****************************************************************/
	/** 函数名:TimerThread
	** 功能描述:发送心跳消息线程主函数
	**参数:无
	**返回值：无
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	void TimerThread(int ttl);
	/*****************************************************************/
	/** 函数名:NewAutoHeartBeatThread
	** 功能描述:新建自动发送心跳消息线程，该线程自动运行
	**参数:
	** 参数名 ttl 【I-输入】自动发送心跳最大事件间隔，每隔最大事件间隔之前，该线程会自动发送一条心跳信息到注册中心
	**返回值：无
	** 全局变量:无
	** 调用模块:
	** 作 者:吴文茂
	** 日 期:2017-07-05
	** 修 改:吴文茂
	** 日 期:2017-07-05
	** 版本0.2
	*/
	/****************************************************************/
	void NewAutoHeartBeatThread(int ttl);

	void SetWatcher(std::string target, std::string key, std::function<void(Response)> callback);
private:
	static void AutoHeartBeat(const boost::system::error_code& e, boost::asio::deadline_timer* t, int ttl, void* ptr);
	void SetAutoHeartBeat(int ttl);

	//微服务名称
	std::string name_;
	//微服务提供者的ip
	std::string host_;
	//微服务的端口
	unsigned short  port_;
	//连接注册中心的客户端指针，初始化时为NULL
	etcd::Client* pclient_;
	//监视器指针，初始化时为NULL
	etcd::Watcher* pwatch_;
	//注册的微服务的老化时间，即最大心跳发送时间
	::google::protobuf::int64 ttl_;
	//注册微服务的租约，一般一个租约对应一个老化时间
	::google::protobuf::int64 leaseId_;
	//注册中心地址，例如"http://192.168.20.251:2379"
	std::string target_;
	//解析微服务地址策略
	PolicyType policy_;

};

class VS_MicroServiceWatcher {
public:
	VS_MicroServiceWatcher() {
		target_ = ""; 
		pwatch_ = NULL;
	}
	~VS_MicroServiceWatcher() {
		delWatcher();
	}
	void SetWatcher(std::string target, std::string key, std::function<void(Response)> callback);
	void SetWatcher(std::string target, std::string name, std::string ip, int port,std::function<void(Response)> callback);
	void SetWatcher2(std::string target, std::string name, std::string ip, int port, watcher_callback f, void* ptr);
	void SetWatcher2(std::string target, std::string key, watcher_callback f, void* ptr);
	void SetWatcher2(std::string target, std::string name, std::string address,watcher_callback f,void* ptr);
	void delWatcher();
private:
	std::string target_;
	std::string key_;
	etcd::Watcher* pwatch_;
};
}
#endif // !__VORX_SERVICE_H__