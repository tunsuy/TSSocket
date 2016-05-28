// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef PROTOBUF_srvhead_2eproto__INCLUDED
#define PROTOBUF_srvhead_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>

namespace com {
namespace sangfor {
namespace moa {
namespace protobuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_srvhead_2eproto();
void protobuf_AssignDesc_srvhead_2eproto();
void protobuf_ShutdownFile_srvhead_2eproto();

class PB_ModMsgId;
class PB_SrvHead;

// ===================================================================

class PB_ModMsgId : public ::google::protobuf::Message {
 public:
  PB_ModMsgId();
  virtual ~PB_ModMsgId();
  
  PB_ModMsgId(const PB_ModMsgId& from);
  
  inline PB_ModMsgId& operator=(const PB_ModMsgId& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const PB_ModMsgId& default_instance();
  void Swap(PB_ModMsgId* other);
  
  // implements Message ----------------------------------------------
  
  PB_ModMsgId* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PB_ModMsgId& from);
  void MergeFrom(const PB_ModMsgId& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const { _cached_size_ = size; }
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional uint64 client_req_id = 1;
  inline bool has_client_req_id() const;
  inline void clear_client_req_id();
  static const int kClientReqIdFieldNumber = 1;
  inline ::google::protobuf::uint64 client_req_id() const;
  inline void set_client_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 disp_req_id = 2;
  inline bool has_disp_req_id() const;
  inline void clear_disp_req_id();
  static const int kDispReqIdFieldNumber = 2;
  inline ::google::protobuf::uint64 disp_req_id() const;
  inline void set_disp_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 workflow_req_id = 7;
  inline bool has_workflow_req_id() const;
  inline void clear_workflow_req_id();
  static const int kWorkflowReqIdFieldNumber = 7;
  inline ::google::protobuf::uint64 workflow_req_id() const;
  inline void set_workflow_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 servermap_req_id = 14;
  inline bool has_servermap_req_id() const;
  inline void clear_servermap_req_id();
  static const int kServermapReqIdFieldNumber = 14;
  inline ::google::protobuf::uint64 servermap_req_id() const;
  inline void set_servermap_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 notify_req_id = 17;
  inline bool has_notify_req_id() const;
  inline void clear_notify_req_id();
  static const int kNotifyReqIdFieldNumber = 17;
  inline ::google::protobuf::uint64 notify_req_id() const;
  inline void set_notify_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 file_req_id = 18;
  inline bool has_file_req_id() const;
  inline void clear_file_req_id();
  static const int kFileReqIdFieldNumber = 18;
  inline ::google::protobuf::uint64 file_req_id() const;
  inline void set_file_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 srvrpc_req_id = 19;
  inline bool has_srvrpc_req_id() const;
  inline void clear_srvrpc_req_id();
  static const int kSrvrpcReqIdFieldNumber = 19;
  inline ::google::protobuf::uint64 srvrpc_req_id() const;
  inline void set_srvrpc_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 entry_req_id = 20;
  inline bool has_entry_req_id() const;
  inline void clear_entry_req_id();
  static const int kEntryReqIdFieldNumber = 20;
  inline ::google::protobuf::uint64 entry_req_id() const;
  inline void set_entry_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 workflowdisp_req_id = 21;
  inline bool has_workflowdisp_req_id() const;
  inline void clear_workflowdisp_req_id();
  static const int kWorkflowdispReqIdFieldNumber = 21;
  inline ::google::protobuf::uint64 workflowdisp_req_id() const;
  inline void set_workflowdisp_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 mtunnel_req_id = 22;
  inline bool has_mtunnel_req_id() const;
  inline void clear_mtunnel_req_id();
  static const int kMtunnelReqIdFieldNumber = 22;
  inline ::google::protobuf::uint64 mtunnel_req_id() const;
  inline void set_mtunnel_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 web_req_id = 23;
  inline bool has_web_req_id() const;
  inline void clear_web_req_id();
  static const int kWebReqIdFieldNumber = 23;
  inline ::google::protobuf::uint64 web_req_id() const;
  inline void set_web_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 reg_req_id = 24;
  inline bool has_reg_req_id() const;
  inline void clear_reg_req_id();
  static const int kRegReqIdFieldNumber = 24;
  inline ::google::protobuf::uint64 reg_req_id() const;
  inline void set_reg_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 httpport_req_id = 25;
  inline bool has_httpport_req_id() const;
  inline void clear_httpport_req_id();
  static const int kHttpportReqIdFieldNumber = 25;
  inline ::google::protobuf::uint64 httpport_req_id() const;
  inline void set_httpport_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 oprtproxy_req_id = 26;
  inline bool has_oprtproxy_req_id() const;
  inline void clear_oprtproxy_req_id();
  static const int kOprtproxyReqIdFieldNumber = 26;
  inline ::google::protobuf::uint64 oprtproxy_req_id() const;
  inline void set_oprtproxy_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 oprtdisp_req_id = 27;
  inline bool has_oprtdisp_req_id() const;
  inline void clear_oprtdisp_req_id();
  static const int kOprtdispReqIdFieldNumber = 27;
  inline ::google::protobuf::uint64 oprtdisp_req_id() const;
  inline void set_oprtdisp_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 legwork_req_id = 28;
  inline bool has_legwork_req_id() const;
  inline void clear_legwork_req_id();
  static const int kLegworkReqIdFieldNumber = 28;
  inline ::google::protobuf::uint64 legwork_req_id() const;
  inline void set_legwork_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 permit_req_id = 29;
  inline bool has_permit_req_id() const;
  inline void clear_permit_req_id();
  static const int kPermitReqIdFieldNumber = 29;
  inline ::google::protobuf::uint64 permit_req_id() const;
  inline void set_permit_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 acc_conn_id = 51;
  inline bool has_acc_conn_id() const;
  inline void clear_acc_conn_id();
  static const int kAccConnIdFieldNumber = 51;
  inline ::google::protobuf::uint64 acc_conn_id() const;
  inline void set_acc_conn_id(::google::protobuf::uint64 value);
  
  // optional uint64 acc_cli_req_id = 52;
  inline bool has_acc_cli_req_id() const;
  inline void clear_acc_cli_req_id();
  static const int kAccCliReqIdFieldNumber = 52;
  inline ::google::protobuf::uint64 acc_cli_req_id() const;
  inline void set_acc_cli_req_id(::google::protobuf::uint64 value);
  
  // optional uint64 acc_data_seq = 53;
  inline bool has_acc_data_seq() const;
  inline void clear_acc_data_seq();
  static const int kAccDataSeqFieldNumber = 53;
  inline ::google::protobuf::uint64 acc_data_seq() const;
  inline void set_acc_data_seq(::google::protobuf::uint64 value);
  
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::uint64 client_req_id_;
  ::google::protobuf::uint64 disp_req_id_;
  ::google::protobuf::uint64 workflow_req_id_;
  ::google::protobuf::uint64 servermap_req_id_;
  ::google::protobuf::uint64 notify_req_id_;
  ::google::protobuf::uint64 file_req_id_;
  ::google::protobuf::uint64 srvrpc_req_id_;
  ::google::protobuf::uint64 entry_req_id_;
  ::google::protobuf::uint64 workflowdisp_req_id_;
  ::google::protobuf::uint64 mtunnel_req_id_;
  ::google::protobuf::uint64 web_req_id_;
  ::google::protobuf::uint64 reg_req_id_;
  ::google::protobuf::uint64 httpport_req_id_;
  ::google::protobuf::uint64 oprtproxy_req_id_;
  ::google::protobuf::uint64 oprtdisp_req_id_;
  ::google::protobuf::uint64 legwork_req_id_;
  ::google::protobuf::uint64 permit_req_id_;
  ::google::protobuf::uint64 acc_conn_id_;
  ::google::protobuf::uint64 acc_cli_req_id_;
  ::google::protobuf::uint64 acc_data_seq_;
  friend void  protobuf_AddDesc_srvhead_2eproto();
  friend void protobuf_AssignDesc_srvhead_2eproto();
  friend void protobuf_ShutdownFile_srvhead_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(20 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static PB_ModMsgId* default_instance_;
};
// -------------------------------------------------------------------

class PB_SrvHead : public ::google::protobuf::Message {
 public:
  PB_SrvHead();
  virtual ~PB_SrvHead();
  
  PB_SrvHead(const PB_SrvHead& from);
  
  inline PB_SrvHead& operator=(const PB_SrvHead& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const PB_SrvHead& default_instance();
  void Swap(PB_SrvHead* other);
  
  // implements Message ----------------------------------------------
  
  PB_SrvHead* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PB_SrvHead& from);
  void MergeFrom(const PB_SrvHead& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const { _cached_size_ = size; }
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required uint32 srvop = 1;
  inline bool has_srvop() const;
  inline void clear_srvop();
  static const int kSrvopFieldNumber = 1;
  inline ::google::protobuf::uint32 srvop() const;
  inline void set_srvop(::google::protobuf::uint32 value);
  
  // optional uint32 flag = 2;
  inline bool has_flag() const;
  inline void clear_flag();
  static const int kFlagFieldNumber = 2;
  inline ::google::protobuf::uint32 flag() const;
  inline void set_flag(::google::protobuf::uint32 value);
  
  // optional .com.sangfor.moa.protobuf.PB_ModMsgId mmid = 3;
  inline bool has_mmid() const;
  inline void clear_mmid();
  static const int kMmidFieldNumber = 3;
  inline const ::com::sangfor::moa::protobuf::PB_ModMsgId& mmid() const;
  inline ::com::sangfor::moa::protobuf::PB_ModMsgId* mutable_mmid();
  
  // optional int64 from_did = 4;
  inline bool has_from_did() const;
  inline void clear_from_did();
  static const int kFromDidFieldNumber = 4;
  inline ::google::protobuf::int64 from_did() const;
  inline void set_from_did(::google::protobuf::int64 value);
  
  // optional int64 from_pid = 5;
  inline bool has_from_pid() const;
  inline void clear_from_pid();
  static const int kFromPidFieldNumber = 5;
  inline ::google::protobuf::int64 from_pid() const;
  inline void set_from_pid(::google::protobuf::int64 value);
  
  // optional int64 to_did = 6;
  inline bool has_to_did() const;
  inline void clear_to_did();
  static const int kToDidFieldNumber = 6;
  inline ::google::protobuf::int64 to_did() const;
  inline void set_to_did(::google::protobuf::int64 value);
  
  // optional int64 to_pid = 7;
  inline bool has_to_pid() const;
  inline void clear_to_pid();
  static const int kToPidFieldNumber = 7;
  inline ::google::protobuf::int64 to_pid() const;
  inline void set_to_pid(::google::protobuf::int64 value);
  
  // optional int32 err_no = 8 [default = 0];
  inline bool has_err_no() const;
  inline void clear_err_no();
  static const int kErrNoFieldNumber = 8;
  inline ::google::protobuf::int32 err_no() const;
  inline void set_err_no(::google::protobuf::int32 value);
  
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::uint32 srvop_;
  ::google::protobuf::uint32 flag_;
  ::com::sangfor::moa::protobuf::PB_ModMsgId* mmid_;
  ::google::protobuf::int64 from_did_;
  ::google::protobuf::int64 from_pid_;
  ::google::protobuf::int64 to_did_;
  ::google::protobuf::int64 to_pid_;
  ::google::protobuf::int32 err_no_;
  friend void  protobuf_AddDesc_srvhead_2eproto();
  friend void protobuf_AssignDesc_srvhead_2eproto();
  friend void protobuf_ShutdownFile_srvhead_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static PB_SrvHead* default_instance_;
};
// ===================================================================


// ===================================================================


// ===================================================================

// PB_ModMsgId

// optional uint64 client_req_id = 1;
inline bool PB_ModMsgId::has_client_req_id() const {
  return _has_bit(0);
}
inline void PB_ModMsgId::clear_client_req_id() {
  client_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(0);
}
inline ::google::protobuf::uint64 PB_ModMsgId::client_req_id() const {
  return client_req_id_;
}
inline void PB_ModMsgId::set_client_req_id(::google::protobuf::uint64 value) {
  _set_bit(0);
  client_req_id_ = value;
}

// optional uint64 disp_req_id = 2;
inline bool PB_ModMsgId::has_disp_req_id() const {
  return _has_bit(1);
}
inline void PB_ModMsgId::clear_disp_req_id() {
  disp_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(1);
}
inline ::google::protobuf::uint64 PB_ModMsgId::disp_req_id() const {
  return disp_req_id_;
}
inline void PB_ModMsgId::set_disp_req_id(::google::protobuf::uint64 value) {
  _set_bit(1);
  disp_req_id_ = value;
}

// optional uint64 workflow_req_id = 7;
inline bool PB_ModMsgId::has_workflow_req_id() const {
  return _has_bit(2);
}
inline void PB_ModMsgId::clear_workflow_req_id() {
  workflow_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(2);
}
inline ::google::protobuf::uint64 PB_ModMsgId::workflow_req_id() const {
  return workflow_req_id_;
}
inline void PB_ModMsgId::set_workflow_req_id(::google::protobuf::uint64 value) {
  _set_bit(2);
  workflow_req_id_ = value;
}

// optional uint64 servermap_req_id = 14;
inline bool PB_ModMsgId::has_servermap_req_id() const {
  return _has_bit(3);
}
inline void PB_ModMsgId::clear_servermap_req_id() {
  servermap_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(3);
}
inline ::google::protobuf::uint64 PB_ModMsgId::servermap_req_id() const {
  return servermap_req_id_;
}
inline void PB_ModMsgId::set_servermap_req_id(::google::protobuf::uint64 value) {
  _set_bit(3);
  servermap_req_id_ = value;
}

// optional uint64 notify_req_id = 17;
inline bool PB_ModMsgId::has_notify_req_id() const {
  return _has_bit(4);
}
inline void PB_ModMsgId::clear_notify_req_id() {
  notify_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(4);
}
inline ::google::protobuf::uint64 PB_ModMsgId::notify_req_id() const {
  return notify_req_id_;
}
inline void PB_ModMsgId::set_notify_req_id(::google::protobuf::uint64 value) {
  _set_bit(4);
  notify_req_id_ = value;
}

// optional uint64 file_req_id = 18;
inline bool PB_ModMsgId::has_file_req_id() const {
  return _has_bit(5);
}
inline void PB_ModMsgId::clear_file_req_id() {
  file_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(5);
}
inline ::google::protobuf::uint64 PB_ModMsgId::file_req_id() const {
  return file_req_id_;
}
inline void PB_ModMsgId::set_file_req_id(::google::protobuf::uint64 value) {
  _set_bit(5);
  file_req_id_ = value;
}

// optional uint64 srvrpc_req_id = 19;
inline bool PB_ModMsgId::has_srvrpc_req_id() const {
  return _has_bit(6);
}
inline void PB_ModMsgId::clear_srvrpc_req_id() {
  srvrpc_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(6);
}
inline ::google::protobuf::uint64 PB_ModMsgId::srvrpc_req_id() const {
  return srvrpc_req_id_;
}
inline void PB_ModMsgId::set_srvrpc_req_id(::google::protobuf::uint64 value) {
  _set_bit(6);
  srvrpc_req_id_ = value;
}

// optional uint64 entry_req_id = 20;
inline bool PB_ModMsgId::has_entry_req_id() const {
  return _has_bit(7);
}
inline void PB_ModMsgId::clear_entry_req_id() {
  entry_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(7);
}
inline ::google::protobuf::uint64 PB_ModMsgId::entry_req_id() const {
  return entry_req_id_;
}
inline void PB_ModMsgId::set_entry_req_id(::google::protobuf::uint64 value) {
  _set_bit(7);
  entry_req_id_ = value;
}

// optional uint64 workflowdisp_req_id = 21;
inline bool PB_ModMsgId::has_workflowdisp_req_id() const {
  return _has_bit(8);
}
inline void PB_ModMsgId::clear_workflowdisp_req_id() {
  workflowdisp_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(8);
}
inline ::google::protobuf::uint64 PB_ModMsgId::workflowdisp_req_id() const {
  return workflowdisp_req_id_;
}
inline void PB_ModMsgId::set_workflowdisp_req_id(::google::protobuf::uint64 value) {
  _set_bit(8);
  workflowdisp_req_id_ = value;
}

// optional uint64 mtunnel_req_id = 22;
inline bool PB_ModMsgId::has_mtunnel_req_id() const {
  return _has_bit(9);
}
inline void PB_ModMsgId::clear_mtunnel_req_id() {
  mtunnel_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(9);
}
inline ::google::protobuf::uint64 PB_ModMsgId::mtunnel_req_id() const {
  return mtunnel_req_id_;
}
inline void PB_ModMsgId::set_mtunnel_req_id(::google::protobuf::uint64 value) {
  _set_bit(9);
  mtunnel_req_id_ = value;
}

// optional uint64 web_req_id = 23;
inline bool PB_ModMsgId::has_web_req_id() const {
  return _has_bit(10);
}
inline void PB_ModMsgId::clear_web_req_id() {
  web_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(10);
}
inline ::google::protobuf::uint64 PB_ModMsgId::web_req_id() const {
  return web_req_id_;
}
inline void PB_ModMsgId::set_web_req_id(::google::protobuf::uint64 value) {
  _set_bit(10);
  web_req_id_ = value;
}

// optional uint64 reg_req_id = 24;
inline bool PB_ModMsgId::has_reg_req_id() const {
  return _has_bit(11);
}
inline void PB_ModMsgId::clear_reg_req_id() {
  reg_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(11);
}
inline ::google::protobuf::uint64 PB_ModMsgId::reg_req_id() const {
  return reg_req_id_;
}
inline void PB_ModMsgId::set_reg_req_id(::google::protobuf::uint64 value) {
  _set_bit(11);
  reg_req_id_ = value;
}

// optional uint64 httpport_req_id = 25;
inline bool PB_ModMsgId::has_httpport_req_id() const {
  return _has_bit(12);
}
inline void PB_ModMsgId::clear_httpport_req_id() {
  httpport_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(12);
}
inline ::google::protobuf::uint64 PB_ModMsgId::httpport_req_id() const {
  return httpport_req_id_;
}
inline void PB_ModMsgId::set_httpport_req_id(::google::protobuf::uint64 value) {
  _set_bit(12);
  httpport_req_id_ = value;
}

// optional uint64 oprtproxy_req_id = 26;
inline bool PB_ModMsgId::has_oprtproxy_req_id() const {
  return _has_bit(13);
}
inline void PB_ModMsgId::clear_oprtproxy_req_id() {
  oprtproxy_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(13);
}
inline ::google::protobuf::uint64 PB_ModMsgId::oprtproxy_req_id() const {
  return oprtproxy_req_id_;
}
inline void PB_ModMsgId::set_oprtproxy_req_id(::google::protobuf::uint64 value) {
  _set_bit(13);
  oprtproxy_req_id_ = value;
}

// optional uint64 oprtdisp_req_id = 27;
inline bool PB_ModMsgId::has_oprtdisp_req_id() const {
  return _has_bit(14);
}
inline void PB_ModMsgId::clear_oprtdisp_req_id() {
  oprtdisp_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(14);
}
inline ::google::protobuf::uint64 PB_ModMsgId::oprtdisp_req_id() const {
  return oprtdisp_req_id_;
}
inline void PB_ModMsgId::set_oprtdisp_req_id(::google::protobuf::uint64 value) {
  _set_bit(14);
  oprtdisp_req_id_ = value;
}

// optional uint64 legwork_req_id = 28;
inline bool PB_ModMsgId::has_legwork_req_id() const {
  return _has_bit(15);
}
inline void PB_ModMsgId::clear_legwork_req_id() {
  legwork_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(15);
}
inline ::google::protobuf::uint64 PB_ModMsgId::legwork_req_id() const {
  return legwork_req_id_;
}
inline void PB_ModMsgId::set_legwork_req_id(::google::protobuf::uint64 value) {
  _set_bit(15);
  legwork_req_id_ = value;
}

// optional uint64 permit_req_id = 29;
inline bool PB_ModMsgId::has_permit_req_id() const {
  return _has_bit(16);
}
inline void PB_ModMsgId::clear_permit_req_id() {
  permit_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(16);
}
inline ::google::protobuf::uint64 PB_ModMsgId::permit_req_id() const {
  return permit_req_id_;
}
inline void PB_ModMsgId::set_permit_req_id(::google::protobuf::uint64 value) {
  _set_bit(16);
  permit_req_id_ = value;
}

// optional uint64 acc_conn_id = 51;
inline bool PB_ModMsgId::has_acc_conn_id() const {
  return _has_bit(17);
}
inline void PB_ModMsgId::clear_acc_conn_id() {
  acc_conn_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(17);
}
inline ::google::protobuf::uint64 PB_ModMsgId::acc_conn_id() const {
  return acc_conn_id_;
}
inline void PB_ModMsgId::set_acc_conn_id(::google::protobuf::uint64 value) {
  _set_bit(17);
  acc_conn_id_ = value;
}

// optional uint64 acc_cli_req_id = 52;
inline bool PB_ModMsgId::has_acc_cli_req_id() const {
  return _has_bit(18);
}
inline void PB_ModMsgId::clear_acc_cli_req_id() {
  acc_cli_req_id_ = GOOGLE_ULONGLONG(0);
  _clear_bit(18);
}
inline ::google::protobuf::uint64 PB_ModMsgId::acc_cli_req_id() const {
  return acc_cli_req_id_;
}
inline void PB_ModMsgId::set_acc_cli_req_id(::google::protobuf::uint64 value) {
  _set_bit(18);
  acc_cli_req_id_ = value;
}

// optional uint64 acc_data_seq = 53;
inline bool PB_ModMsgId::has_acc_data_seq() const {
  return _has_bit(19);
}
inline void PB_ModMsgId::clear_acc_data_seq() {
  acc_data_seq_ = GOOGLE_ULONGLONG(0);
  _clear_bit(19);
}
inline ::google::protobuf::uint64 PB_ModMsgId::acc_data_seq() const {
  return acc_data_seq_;
}
inline void PB_ModMsgId::set_acc_data_seq(::google::protobuf::uint64 value) {
  _set_bit(19);
  acc_data_seq_ = value;
}

// -------------------------------------------------------------------

// PB_SrvHead

// required uint32 srvop = 1;
inline bool PB_SrvHead::has_srvop() const {
  return _has_bit(0);
}
inline void PB_SrvHead::clear_srvop() {
  srvop_ = 0u;
  _clear_bit(0);
}
inline ::google::protobuf::uint32 PB_SrvHead::srvop() const {
  return srvop_;
}
inline void PB_SrvHead::set_srvop(::google::protobuf::uint32 value) {
  _set_bit(0);
  srvop_ = value;
}

// optional uint32 flag = 2;
inline bool PB_SrvHead::has_flag() const {
  return _has_bit(1);
}
inline void PB_SrvHead::clear_flag() {
  flag_ = 0u;
  _clear_bit(1);
}
inline ::google::protobuf::uint32 PB_SrvHead::flag() const {
  return flag_;
}
inline void PB_SrvHead::set_flag(::google::protobuf::uint32 value) {
  _set_bit(1);
  flag_ = value;
}

// optional .com.sangfor.moa.protobuf.PB_ModMsgId mmid = 3;
inline bool PB_SrvHead::has_mmid() const {
  return _has_bit(2);
}
inline void PB_SrvHead::clear_mmid() {
  if (mmid_ != NULL) mmid_->::com::sangfor::moa::protobuf::PB_ModMsgId::Clear();
  _clear_bit(2);
}
inline const ::com::sangfor::moa::protobuf::PB_ModMsgId& PB_SrvHead::mmid() const {
  return mmid_ != NULL ? *mmid_ : *default_instance_->mmid_;
}
inline ::com::sangfor::moa::protobuf::PB_ModMsgId* PB_SrvHead::mutable_mmid() {
  _set_bit(2);
  if (mmid_ == NULL) mmid_ = new ::com::sangfor::moa::protobuf::PB_ModMsgId;
  return mmid_;
}

// optional int64 from_did = 4;
inline bool PB_SrvHead::has_from_did() const {
  return _has_bit(3);
}
inline void PB_SrvHead::clear_from_did() {
  from_did_ = GOOGLE_LONGLONG(0);
  _clear_bit(3);
}
inline ::google::protobuf::int64 PB_SrvHead::from_did() const {
  return from_did_;
}
inline void PB_SrvHead::set_from_did(::google::protobuf::int64 value) {
  _set_bit(3);
  from_did_ = value;
}

// optional int64 from_pid = 5;
inline bool PB_SrvHead::has_from_pid() const {
  return _has_bit(4);
}
inline void PB_SrvHead::clear_from_pid() {
  from_pid_ = GOOGLE_LONGLONG(0);
  _clear_bit(4);
}
inline ::google::protobuf::int64 PB_SrvHead::from_pid() const {
  return from_pid_;
}
inline void PB_SrvHead::set_from_pid(::google::protobuf::int64 value) {
  _set_bit(4);
  from_pid_ = value;
}

// optional int64 to_did = 6;
inline bool PB_SrvHead::has_to_did() const {
  return _has_bit(5);
}
inline void PB_SrvHead::clear_to_did() {
  to_did_ = GOOGLE_LONGLONG(0);
  _clear_bit(5);
}
inline ::google::protobuf::int64 PB_SrvHead::to_did() const {
  return to_did_;
}
inline void PB_SrvHead::set_to_did(::google::protobuf::int64 value) {
  _set_bit(5);
  to_did_ = value;
}

// optional int64 to_pid = 7;
inline bool PB_SrvHead::has_to_pid() const {
  return _has_bit(6);
}
inline void PB_SrvHead::clear_to_pid() {
  to_pid_ = GOOGLE_LONGLONG(0);
  _clear_bit(6);
}
inline ::google::protobuf::int64 PB_SrvHead::to_pid() const {
  return to_pid_;
}
inline void PB_SrvHead::set_to_pid(::google::protobuf::int64 value) {
  _set_bit(6);
  to_pid_ = value;
}

// optional int32 err_no = 8 [default = 0];
inline bool PB_SrvHead::has_err_no() const {
  return _has_bit(7);
}
inline void PB_SrvHead::clear_err_no() {
  err_no_ = 0;
  _clear_bit(7);
}
inline ::google::protobuf::int32 PB_SrvHead::err_no() const {
  return err_no_;
}
inline void PB_SrvHead::set_err_no(::google::protobuf::int32 value) {
  _set_bit(7);
  err_no_ = value;
}


}  // namespace protobuf
}  // namespace moa
}  // namespace sangfor
}  // namespace com

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

#endif  // PROTOBUF_srvhead_2eproto__INCLUDED