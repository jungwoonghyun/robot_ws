// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from message_interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__STATE__STRUCT_H_
#define MESSAGE_INTERFACE__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/State in the package message_interface.
/**
  * State.msg
 */
typedef struct message_interface__msg__State
{
  int32_t statenum;
} message_interface__msg__State;

// Struct for a sequence of message_interface__msg__State.
typedef struct message_interface__msg__State__Sequence
{
  message_interface__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} message_interface__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__STATE__STRUCT_H_
