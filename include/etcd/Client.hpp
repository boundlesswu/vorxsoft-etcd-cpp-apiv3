#ifndef __ETCD_CLIENT_HPP__
#define __ETCD_CLIENT_HPP__

#include <ppl.h>
#include <pplx/pplxtasks.h>

#include "etcd/Response.hpp"
#include "v3/Transaction.hpp"
#include "v3/AsyncTxnResponse.hpp"
#include "v3/Action.hpp"

#include <string>

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"


using etcdserverpb::KV;
using etcdserverpb::Watch;
using etcdserverpb::Lease;

namespace etcd
{
  /**
   * Client is responsible for maintaining a connection towards an etcd server.
   * Etcd operations can be reached via the methods of the client.
   */
  class Client
  {
  public:
    /**
     * Constructs an etcd client object.
     * @param etcd_url is the url of the etcd server to connect to, like "http://127.0.0.1:4001"
     */
    Client(std::string const & etcd_url);

    /**
     * Sends a get request to the etcd server
     * @param key is the key to be read
     */
    pplx::task<Response> get(std::string const & key);

    /**
     * Sets the value of a key. The key will be modified if already exists or created
     * if it does not exists.
     * @param key is the key to be created or modified
     * @param value is the new value to be set
     */
    pplx::task<Response> set(std::string const & key, std::string const & value, int ttl = 0);

    /**
     * Sets the value of a key. The key will be modified if already exists or created
     * if it does not exists.
     * @param key is the key to be created or modified
     * @param value is the new value to be set
     * @param leaseId is the lease attached to the key
     */
    pplx::task<Response> set(std::string const & key, std::string const & value, int64_t leaseId);


    /**
     * Creates a new key and sets it's value. Fails if the key already exists.
     * @param key is the key to be created
     * @param value is the value to be set
     */
    pplx::task<Response> add(std::string const & key, std::string const & value, int ttl = 0);

    /**
     * Creates a new key and sets it's value. Fails if the key already exists.
     * @param key is the key to be created
     * @param value is the value to be set
     * @param leaseId is the lease attached to the key
     */
    pplx::task<Response> add(std::string const & key, std::string const & value, int64_t leaseId);

    /**
     * Modifies an existing key. Fails if the key does not exists.
     * @param key is the key to be modified
     * @param value is the new value to be set
     */
    pplx::task<Response> modify(std::string const & key, std::string const & value, int ttl = 0);

    /**
     * Modifies an existing key. Fails if the key does not exists.
     * @param key is the key to be modified
     * @param value is the new value to be set
     * @param leaseId is the lease attached to the key
     */
    pplx::task<Response> modify(std::string const & key, std::string const & value, int64_t leaseId);

    /**
     * Modifies an existing key only if it has a specific value. Fails if the key does not exists
     * or the original value differs from the expected one.
     * @param key is the key to be modified
     * @param value is the new value to be set
     * @param old_value is the value to be replaced
     */
    pplx::task<Response> modify_if(std::string const & key, std::string const & value, std::string const & old_value, int ttl = 0);

    /**
     * Modifies an existing key only if it has a specific value. Fails if the key does not exists
     * or the original value differs from the expected one.
     * @param key is the key to be modified
     * @param value is the new value to be set
     * @param old_value is the value to be replaced
     * @param leaseId is the lease attached to the key
     */
    pplx::task<Response> modify_if(std::string const & key, std::string const & value, std::string const & old_value, int64_t leaseId);

    /**
     * Modifies an existing key only if it has a specific modification index value. Fails if the key
     * does not exists or the modification index of the previous value differs from the expected one.
     * @param key is the key to be modified
     * @param value is the new value to be set
     * @param old_index is the expected index of the original value
     */
    pplx::task<Response> modify_if(std::string const & key, std::string const & value, int old_index, int ttl = 0);

    /**
     * Modifies an existing key only if it has a specific modification index value. Fails if the key
     * does not exists or the modification index of the previous value differs from the expected one.
     * @param key is the key to be modified
     * @param value is the new value to be set
     * @param old_index is the expected index of the original value
     * @param leaseId is the lease attached to the key
     */
    pplx::task<Response> modify_if(std::string const & key, std::string const & value, int old_index, int64_t leaseId);

    /**
     * Removes a single key. The key has to point to a plain, non directory entry.
     * @param key is the key to be deleted
     */
    pplx::task<Response> rm(std::string const & key);

    /**
     * Removes a single key but only if it has a specific value. Fails if the key does not exists
     * or the its value differs from the expected one.
     * @param key is the key to be deleted
     */
    pplx::task<Response> rm_if(std::string const & key, std::string const & old_value);

    /**
     * Removes an existing key only if it has a specific modification index value. Fails if the key
     * does not exists or the modification index of it differs from the expected one.
     * @param key is the key to be deleted
     * @param old_index is the expected index of the existing value
     */
    pplx::task<Response> rm_if(std::string const & key, int old_index);

    /**
     * Gets a directory listing of the directory identified by the key.
     * @param key is the key to be listed
     */
    pplx::task<Response> ls(std::string const & key);


    /**
     * Removes a directory node. Fails if the parent directory dos not exists or not a directory.
     * @param key is the directory to be created to be listed
     * @param recursive if true then delete a whole subtree, otherwise deletes only an empty directory.
     */
    pplx::task<Response> rmdir(std::string const & key, bool recursive = false);

    /**
     * Watches for changes of a key or a subtree. Please note that if you watch e.g. "/testdir" and
     * a new key is created, like "/testdir/newkey" then no change happened in the value of
     * "/testdir" so your watch will not detect this. If you want to detect addition and deletion of
     * directory entries then you have to do a recursive watch.
     * @param key is the value or directory to be watched
     * @param recursive if true watch a whole subtree
     */
    pplx::task<Response> watch(std::string const & key, bool recursive = false);

    /**
     * Watches for changes of a key or a subtree from a specific index. The index value can be in the "past".
     * @param key is the value or directory to be watched
     * @param fromIndex the first index we are interested in
     * @param recursive if true watch a whole subtree
     */
    pplx::task<Response> watch(std::string const & key, int fromIndex, bool recursive = false);

    /**
     * Grants a lease.
     * @param ttl is the time to live of the lease
     */
    pplx::task<Response> leasegrant(int ttl);

	pplx::task<Response> leasekeepalive(google::protobuf::int64 id);

  private:

    std::unique_ptr<KV::Stub> stub_;
    std::unique_ptr<Watch::Stub> watchServiceStub;
    std::unique_ptr<Lease::Stub> leaseServiceStub;
};



}

#endif
