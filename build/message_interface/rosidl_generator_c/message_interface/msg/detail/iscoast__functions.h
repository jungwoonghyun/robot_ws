// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from message_interface:msg/Iscoast.idl
// generated code does not contain a copyright notice

#ifndef MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__FUNCTIONS_H_
#define MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "message_interface/msg/rosidl_generator_c__visibility_control.h"

#include "message_interface/msg/detail/iscoast__struct.h"

/// Initialize msg/Iscoast message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * message_interface__msg__Iscoast
 * )) before or use
 * message_interface__msg__Iscoast__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
bool
message_interface__msg__Iscoast__init(message_interface__msg__Iscoast * msg);

/// Finalize msg/Iscoast message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
void
message_interface__msg__Iscoast__fini(message_interface__msg__Iscoast * msg);

/// Create msg/Iscoast message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * message_interface__msg__Iscoast__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
message_interface__msg__Iscoast *
message_interface__msg__Iscoast__create();

/// Destroy msg/Iscoast message.
/**
 * It calls
 * message_interface__msg__Iscoast__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
void
message_interface__msg__Iscoast__destroy(message_interface__msg__Iscoast * msg);

/// Check for msg/Iscoast message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
bool
message_interface__msg__Iscoast__are_equal(const message_interface__msg__Iscoast * lhs, const message_interface__msg__Iscoast * rhs);

/// Copy a msg/Iscoast message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
bool
message_interface__msg__Iscoast__copy(
  const message_interface__msg__Iscoast * input,
  message_interface__msg__Iscoast * output);

/// Initialize array of msg/Iscoast messages.
/**
 * It allocates the memory for the number of elements and calls
 * message_interface__msg__Iscoast__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
bool
message_interface__msg__Iscoast__Sequence__init(message_interface__msg__Iscoast__Sequence * array, size_t size);

/// Finalize array of msg/Iscoast messages.
/**
 * It calls
 * message_interface__msg__Iscoast__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
void
message_interface__msg__Iscoast__Sequence__fini(message_interface__msg__Iscoast__Sequence * array);

/// Create array of msg/Iscoast messages.
/**
 * It allocates the memory for the array and calls
 * message_interface__msg__Iscoast__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
message_interface__msg__Iscoast__Sequence *
message_interface__msg__Iscoast__Sequence__create(size_t size);

/// Destroy array of msg/Iscoast messages.
/**
 * It calls
 * message_interface__msg__Iscoast__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
void
message_interface__msg__Iscoast__Sequence__destroy(message_interface__msg__Iscoast__Sequence * array);

/// Check for msg/Iscoast message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
bool
message_interface__msg__Iscoast__Sequence__are_equal(const message_interface__msg__Iscoast__Sequence * lhs, const message_interface__msg__Iscoast__Sequence * rhs);

/// Copy an array of msg/Iscoast messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_message_interface
bool
message_interface__msg__Iscoast__Sequence__copy(
  const message_interface__msg__Iscoast__Sequence * input,
  message_interface__msg__Iscoast__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MESSAGE_INTERFACE__MSG__DETAIL__ISCOAST__FUNCTIONS_H_
