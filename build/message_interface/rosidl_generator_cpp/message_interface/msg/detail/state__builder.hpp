// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from message_interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_
#define MESSAGE_INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "message_interface/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace message_interface
{

namespace msg
{

namespace builder
{

class Init_State_statenum
{
public:
  Init_State_statenum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::message_interface::msg::State statenum(::message_interface::msg::State::_statenum_type arg)
  {
    msg_.statenum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::message_interface::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::message_interface::msg::State>()
{
  return message_interface::msg::builder::Init_State_statenum();
}

}  // namespace message_interface

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_
