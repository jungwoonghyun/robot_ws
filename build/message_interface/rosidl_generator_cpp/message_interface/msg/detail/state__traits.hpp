// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from message_interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__STATE__TRAITS_HPP_
#define MESSAGE_INTERFACE__MSG__DETAIL__STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "message_interface/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace message_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const State & msg,
  std::ostream & out)
{
  out << "{";
  // member: statenum
  {
    out << "statenum: ";
    rosidl_generator_traits::value_to_yaml(msg.statenum, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const State & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: statenum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "statenum: ";
    rosidl_generator_traits::value_to_yaml(msg.statenum, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const State & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace message_interface

namespace rosidl_generator_traits
{

[[deprecated("use message_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const message_interface::msg::State & msg,
  std::ostream & out, size_t indentation = 0)
{
  message_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use message_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const message_interface::msg::State & msg)
{
  return message_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<message_interface::msg::State>()
{
  return "message_interface::msg::State";
}

template<>
inline const char * name<message_interface::msg::State>()
{
  return "message_interface/msg/State";
}

template<>
struct has_fixed_size<message_interface::msg::State>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<message_interface::msg::State>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<message_interface::msg::State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__STATE__TRAITS_HPP_
