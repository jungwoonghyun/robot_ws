// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from message_interface:msg/Mode.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__MODE__STRUCT_HPP_
#define MESSAGE_INTERFACE__MSG__DETAIL__MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__message_interface__msg__Mode __attribute__((deprecated))
#else
# define DEPRECATED__message_interface__msg__Mode __declspec(deprecated)
#endif

namespace message_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Mode_
{
  using Type = Mode_<ContainerAllocator>;

  explicit Mode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->modenum = 0l;
    }
  }

  explicit Mode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->modenum = 0l;
    }
  }

  // field types and members
  using _modenum_type =
    int32_t;
  _modenum_type modenum;

  // setters for named parameter idiom
  Type & set__modenum(
    const int32_t & _arg)
  {
    this->modenum = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    message_interface::msg::Mode_<ContainerAllocator> *;
  using ConstRawPtr =
    const message_interface::msg::Mode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<message_interface::msg::Mode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<message_interface::msg::Mode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      message_interface::msg::Mode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<message_interface::msg::Mode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      message_interface::msg::Mode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<message_interface::msg::Mode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<message_interface::msg::Mode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<message_interface::msg::Mode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__message_interface__msg__Mode
    std::shared_ptr<message_interface::msg::Mode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__message_interface__msg__Mode
    std::shared_ptr<message_interface::msg::Mode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mode_ & other) const
  {
    if (this->modenum != other.modenum) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mode_

// alias to use template instance with default allocator
using Mode =
  message_interface::msg::Mode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace message_interface

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__MODE__STRUCT_HPP_
