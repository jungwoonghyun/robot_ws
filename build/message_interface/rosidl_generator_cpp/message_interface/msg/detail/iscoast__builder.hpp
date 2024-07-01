// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from message_interface:msg/Iscoast.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__BUILDER_HPP_
#define MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "message_interface/msg/detail/iscoast__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace message_interface
{

namespace msg
{

namespace builder
{

class Init_Iscoast_iscoast
{
public:
  Init_Iscoast_iscoast()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::message_interface::msg::Iscoast iscoast(::message_interface::msg::Iscoast::_iscoast_type arg)
  {
    msg_.iscoast = std::move(arg);
    return std::move(msg_);
  }

private:
  ::message_interface::msg::Iscoast msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::message_interface::msg::Iscoast>()
{
  return message_interface::msg::builder::Init_Iscoast_iscoast();
}

}  // namespace message_interface

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__BUILDER_HPP_
