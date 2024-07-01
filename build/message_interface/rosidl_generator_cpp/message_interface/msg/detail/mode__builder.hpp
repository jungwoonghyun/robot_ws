// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from message_interface:msg/Mode.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__MODE__BUILDER_HPP_
#define MESSAGE_INTERFACE__MSG__DETAIL__MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "message_interface/msg/detail/mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace message_interface
{

namespace msg
{

namespace builder
{

class Init_Mode_modenum
{
public:
  Init_Mode_modenum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::message_interface::msg::Mode modenum(::message_interface::msg::Mode::_modenum_type arg)
  {
    msg_.modenum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::message_interface::msg::Mode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::message_interface::msg::Mode>()
{
  return message_interface::msg::builder::Init_Mode_modenum();
}

}  // namespace message_interface

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__MODE__BUILDER_HPP_
