// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from message_interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__STATE__STRUCT_HPP_
#define MESSAGE_INTERFACE__MSG__DETAIL__STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__message_interface__msg__State __attribute__((deprecated))
#else
# define DEPRECATED__message_interface__msg__State __declspec(deprecated)
#endif

namespace message_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct State_
{
  using Type = State_<ContainerAllocator>;

  explicit State_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->statenum = 0l;
    }
  }

  explicit State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->statenum = 0l;
    }
  }

  // field types and members
  using _statenum_type =
    int32_t;
  _statenum_type statenum;

  // setters for named parameter idiom
  Type & set__statenum(
    const int32_t & _arg)
  {
    this->statenum = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    message_interface::msg::State_<ContainerAllocator> *;
  using ConstRawPtr =
    const message_interface::msg::State_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<message_interface::msg::State_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<message_interface::msg::State_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      message_interface::msg::State_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<message_interface::msg::State_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      message_interface::msg::State_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<message_interface::msg::State_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<message_interface::msg::State_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<message_interface::msg::State_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__message_interface__msg__State
    std::shared_ptr<message_interface::msg::State_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__message_interface__msg__State
    std::shared_ptr<message_interface::msg::State_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const State_ & other) const
  {
    if (this->statenum != other.statenum) {
      return false;
    }
    return true;
  }
  bool operator!=(const State_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct State_

// alias to use template instance with default allocator
using State =
  message_interface::msg::State_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace message_interface

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__STATE__STRUCT_HPP_
