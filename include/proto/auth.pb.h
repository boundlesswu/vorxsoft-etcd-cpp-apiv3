// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: etcdv3_auth.proto

#ifndef PROTOBUF_etcdv3_5fauth_2eproto__INCLUDED
#define PROTOBUF_etcdv3_5fauth_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace authpb {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_etcdv3_5fauth_2eproto();
void protobuf_AssignDesc_etcdv3_5fauth_2eproto();
void protobuf_ShutdownFile_etcdv3_5fauth_2eproto();

class Permission;
class Role;
class User;

enum Permission_Type {
  Permission_Type_READ = 0,
  Permission_Type_WRITE = 1,
  Permission_Type_READWRITE = 2,
  Permission_Type_Permission_Type_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Permission_Type_Permission_Type_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Permission_Type_IsValid(int value);
const Permission_Type Permission_Type_Type_MIN = Permission_Type_READ;
const Permission_Type Permission_Type_Type_MAX = Permission_Type_READWRITE;
const int Permission_Type_Type_ARRAYSIZE = Permission_Type_Type_MAX + 1;

const ::google::protobuf::EnumDescriptor* Permission_Type_descriptor();
inline const ::std::string& Permission_Type_Name(Permission_Type value) {
  return ::google::protobuf::internal::NameOfEnum(
    Permission_Type_descriptor(), value);
}
inline bool Permission_Type_Parse(
    const ::std::string& name, Permission_Type* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Permission_Type>(
    Permission_Type_descriptor(), name, value);
}
// ===================================================================

class User : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:authpb.User) */ {
 public:
  User();
  virtual ~User();

  User(const User& from);

  inline User& operator=(const User& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const User& default_instance();

  void Swap(User* other);

  // implements Message ----------------------------------------------

  inline User* New() const { return New(NULL); }

  User* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const User& from);
  void MergeFrom(const User& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(User* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const void* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional bytes password = 2;
  void clear_password();
  static const int kPasswordFieldNumber = 2;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  void set_password(const char* value);
  void set_password(const void* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // repeated string roles = 3;
  int roles_size() const;
  void clear_roles();
  static const int kRolesFieldNumber = 3;
  const ::std::string& roles(int index) const;
  ::std::string* mutable_roles(int index);
  void set_roles(int index, const ::std::string& value);
  void set_roles(int index, const char* value);
  void set_roles(int index, const char* value, size_t size);
  ::std::string* add_roles();
  void add_roles(const ::std::string& value);
  void add_roles(const char* value);
  void add_roles(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& roles() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_roles();

  // @@protoc_insertion_point(class_scope:authpb.User)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  ::google::protobuf::RepeatedPtrField< ::std::string> roles_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_etcdv3_5fauth_2eproto();
  friend void protobuf_AssignDesc_etcdv3_5fauth_2eproto();
  friend void protobuf_ShutdownFile_etcdv3_5fauth_2eproto();

  void InitAsDefaultInstance();
  static User* default_instance_;
};
// -------------------------------------------------------------------

class Permission : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:authpb.Permission) */ {
 public:
  Permission();
  virtual ~Permission();

  Permission(const Permission& from);

  inline Permission& operator=(const Permission& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Permission& default_instance();

  void Swap(Permission* other);

  // implements Message ----------------------------------------------

  inline Permission* New() const { return New(NULL); }

  Permission* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Permission& from);
  void MergeFrom(const Permission& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Permission* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Permission_Type Type;
  static const Type READ =
    Permission_Type_READ;
  static const Type WRITE =
    Permission_Type_WRITE;
  static const Type READWRITE =
    Permission_Type_READWRITE;
  static inline bool Type_IsValid(int value) {
    return Permission_Type_IsValid(value);
  }
  static const Type Type_MIN =
    Permission_Type_Type_MIN;
  static const Type Type_MAX =
    Permission_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    Permission_Type_Type_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Type_descriptor() {
    return Permission_Type_descriptor();
  }
  static inline const ::std::string& Type_Name(Type value) {
    return Permission_Type_Name(value);
  }
  static inline bool Type_Parse(const ::std::string& name,
      Type* value) {
    return Permission_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional .authpb.Permission.Type permType = 1;
  void clear_permtype();
  static const int kPermTypeFieldNumber = 1;
  ::authpb::Permission_Type permtype() const;
  void set_permtype(::authpb::Permission_Type value);

  // optional bytes key = 2;
  void clear_key();
  static const int kKeyFieldNumber = 2;
  const ::std::string& key() const;
  void set_key(const ::std::string& value);
  void set_key(const char* value);
  void set_key(const void* value, size_t size);
  ::std::string* mutable_key();
  ::std::string* release_key();
  void set_allocated_key(::std::string* key);

  // optional bytes range_end = 3;
  void clear_range_end();
  static const int kRangeEndFieldNumber = 3;
  const ::std::string& range_end() const;
  void set_range_end(const ::std::string& value);
  void set_range_end(const char* value);
  void set_range_end(const void* value, size_t size);
  ::std::string* mutable_range_end();
  ::std::string* release_range_end();
  void set_allocated_range_end(::std::string* range_end);

  // @@protoc_insertion_point(class_scope:authpb.Permission)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr key_;
  ::google::protobuf::internal::ArenaStringPtr range_end_;
  int permtype_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_etcdv3_5fauth_2eproto();
  friend void protobuf_AssignDesc_etcdv3_5fauth_2eproto();
  friend void protobuf_ShutdownFile_etcdv3_5fauth_2eproto();

  void InitAsDefaultInstance();
  static Permission* default_instance_;
};
// -------------------------------------------------------------------

class Role : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:authpb.Role) */ {
 public:
  Role();
  virtual ~Role();

  Role(const Role& from);

  inline Role& operator=(const Role& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Role& default_instance();

  void Swap(Role* other);

  // implements Message ----------------------------------------------

  inline Role* New() const { return New(NULL); }

  Role* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Role& from);
  void MergeFrom(const Role& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Role* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const void* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // repeated .authpb.Permission keyPermission = 2;
  int keypermission_size() const;
  void clear_keypermission();
  static const int kKeyPermissionFieldNumber = 2;
  const ::authpb::Permission& keypermission(int index) const;
  ::authpb::Permission* mutable_keypermission(int index);
  ::authpb::Permission* add_keypermission();
  ::google::protobuf::RepeatedPtrField< ::authpb::Permission >*
      mutable_keypermission();
  const ::google::protobuf::RepeatedPtrField< ::authpb::Permission >&
      keypermission() const;

  // @@protoc_insertion_point(class_scope:authpb.Role)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::RepeatedPtrField< ::authpb::Permission > keypermission_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_etcdv3_5fauth_2eproto();
  friend void protobuf_AssignDesc_etcdv3_5fauth_2eproto();
  friend void protobuf_ShutdownFile_etcdv3_5fauth_2eproto();

  void InitAsDefaultInstance();
  static Role* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// User

// optional bytes name = 1;
inline void User::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& User::name() const {
  // @@protoc_insertion_point(field_get:authpb.User.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void User::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:authpb.User.name)
}
inline void User::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:authpb.User.name)
}
inline void User::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:authpb.User.name)
}
inline ::std::string* User::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:authpb.User.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* User::release_name() {
  // @@protoc_insertion_point(field_release:authpb.User.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void User::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:authpb.User.name)
}

// optional bytes password = 2;
inline void User::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& User::password() const {
  // @@protoc_insertion_point(field_get:authpb.User.password)
  return password_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void User::set_password(const ::std::string& value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:authpb.User.password)
}
inline void User::set_password(const char* value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:authpb.User.password)
}
inline void User::set_password(const void* value, size_t size) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:authpb.User.password)
}
inline ::std::string* User::mutable_password() {
  
  // @@protoc_insertion_point(field_mutable:authpb.User.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* User::release_password() {
  // @@protoc_insertion_point(field_release:authpb.User.password)
  
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void User::set_allocated_password(::std::string* password) {
  if (password != NULL) {
    
  } else {
    
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:authpb.User.password)
}

// repeated string roles = 3;
inline int User::roles_size() const {
  return roles_.size();
}
inline void User::clear_roles() {
  roles_.Clear();
}
inline const ::std::string& User::roles(int index) const {
  // @@protoc_insertion_point(field_get:authpb.User.roles)
  return roles_.Get(index);
}
inline ::std::string* User::mutable_roles(int index) {
  // @@protoc_insertion_point(field_mutable:authpb.User.roles)
  return roles_.Mutable(index);
}
inline void User::set_roles(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:authpb.User.roles)
  roles_.Mutable(index)->assign(value);
}
inline void User::set_roles(int index, const char* value) {
  roles_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:authpb.User.roles)
}
inline void User::set_roles(int index, const char* value, size_t size) {
  roles_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:authpb.User.roles)
}
inline ::std::string* User::add_roles() {
  // @@protoc_insertion_point(field_add_mutable:authpb.User.roles)
  return roles_.Add();
}
inline void User::add_roles(const ::std::string& value) {
  roles_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:authpb.User.roles)
}
inline void User::add_roles(const char* value) {
  roles_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:authpb.User.roles)
}
inline void User::add_roles(const char* value, size_t size) {
  roles_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:authpb.User.roles)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
User::roles() const {
  // @@protoc_insertion_point(field_list:authpb.User.roles)
  return roles_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
User::mutable_roles() {
  // @@protoc_insertion_point(field_mutable_list:authpb.User.roles)
  return &roles_;
}

// -------------------------------------------------------------------

// Permission

// optional .authpb.Permission.Type permType = 1;
inline void Permission::clear_permtype() {
  permtype_ = 0;
}
inline ::authpb::Permission_Type Permission::permtype() const {
  // @@protoc_insertion_point(field_get:authpb.Permission.permType)
  return static_cast< ::authpb::Permission_Type >(permtype_);
}
inline void Permission::set_permtype(::authpb::Permission_Type value) {
  
  permtype_ = value;
  // @@protoc_insertion_point(field_set:authpb.Permission.permType)
}

// optional bytes key = 2;
inline void Permission::clear_key() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Permission::key() const {
  // @@protoc_insertion_point(field_get:authpb.Permission.key)
  return key_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Permission::set_key(const ::std::string& value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:authpb.Permission.key)
}
inline void Permission::set_key(const char* value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:authpb.Permission.key)
}
inline void Permission::set_key(const void* value, size_t size) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:authpb.Permission.key)
}
inline ::std::string* Permission::mutable_key() {
  
  // @@protoc_insertion_point(field_mutable:authpb.Permission.key)
  return key_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Permission::release_key() {
  // @@protoc_insertion_point(field_release:authpb.Permission.key)
  
  return key_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Permission::set_allocated_key(::std::string* key) {
  if (key != NULL) {
    
  } else {
    
  }
  key_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:authpb.Permission.key)
}

// optional bytes range_end = 3;
inline void Permission::clear_range_end() {
  range_end_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Permission::range_end() const {
  // @@protoc_insertion_point(field_get:authpb.Permission.range_end)
  return range_end_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Permission::set_range_end(const ::std::string& value) {
  
  range_end_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:authpb.Permission.range_end)
}
inline void Permission::set_range_end(const char* value) {
  
  range_end_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:authpb.Permission.range_end)
}
inline void Permission::set_range_end(const void* value, size_t size) {
  
  range_end_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:authpb.Permission.range_end)
}
inline ::std::string* Permission::mutable_range_end() {
  
  // @@protoc_insertion_point(field_mutable:authpb.Permission.range_end)
  return range_end_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Permission::release_range_end() {
  // @@protoc_insertion_point(field_release:authpb.Permission.range_end)
  
  return range_end_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Permission::set_allocated_range_end(::std::string* range_end) {
  if (range_end != NULL) {
    
  } else {
    
  }
  range_end_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), range_end);
  // @@protoc_insertion_point(field_set_allocated:authpb.Permission.range_end)
}

// -------------------------------------------------------------------

// Role

// optional bytes name = 1;
inline void Role::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Role::name() const {
  // @@protoc_insertion_point(field_get:authpb.Role.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Role::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:authpb.Role.name)
}
inline void Role::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:authpb.Role.name)
}
inline void Role::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:authpb.Role.name)
}
inline ::std::string* Role::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:authpb.Role.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Role::release_name() {
  // @@protoc_insertion_point(field_release:authpb.Role.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Role::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:authpb.Role.name)
}

// repeated .authpb.Permission keyPermission = 2;
inline int Role::keypermission_size() const {
  return keypermission_.size();
}
inline void Role::clear_keypermission() {
  keypermission_.Clear();
}
inline const ::authpb::Permission& Role::keypermission(int index) const {
  // @@protoc_insertion_point(field_get:authpb.Role.keyPermission)
  return keypermission_.Get(index);
}
inline ::authpb::Permission* Role::mutable_keypermission(int index) {
  // @@protoc_insertion_point(field_mutable:authpb.Role.keyPermission)
  return keypermission_.Mutable(index);
}
inline ::authpb::Permission* Role::add_keypermission() {
  // @@protoc_insertion_point(field_add:authpb.Role.keyPermission)
  return keypermission_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::authpb::Permission >*
Role::mutable_keypermission() {
  // @@protoc_insertion_point(field_mutable_list:authpb.Role.keyPermission)
  return &keypermission_;
}
inline const ::google::protobuf::RepeatedPtrField< ::authpb::Permission >&
Role::keypermission() const {
  // @@protoc_insertion_point(field_list:authpb.Role.keyPermission)
  return keypermission_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace authpb

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::authpb::Permission_Type> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::authpb::Permission_Type>() {
  return ::authpb::Permission_Type_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_etcdv3_5fauth_2eproto__INCLUDED
