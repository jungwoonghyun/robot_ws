// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from message_interface:msg/Iscoast.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__STRUCT_H_
#define MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Iscoast in the package message_interface.
/**
  * Iscoast.msg
 */
typedef struct message_interface__msg__Iscoast
{
  bool iscoast;
} message_interface__msg__Iscoast;

// Struct for a sequence of message_interface__msg__Iscoast.
typedef struct message_interface__msg__Iscoast__Sequence
{
  message_interface__msg__Iscoast * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} message_interface__msg__Iscoast__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__STRUCT_H_
