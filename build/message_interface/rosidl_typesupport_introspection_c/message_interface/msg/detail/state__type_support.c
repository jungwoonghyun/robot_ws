// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from message_interface:msg/State.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "message_interface/msg/detail/state__rosidl_typesupport_introspection_c.h"
#include "message_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "message_interface/msg/detail/state__functions.h"
#include "message_interface/msg/detail/state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void message_interface__msg__State__rosidl_typesupport_introspection_c__State_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  message_interface__msg__State__init(message_memory);
}

void message_interface__msg__State__rosidl_typesupport_introspection_c__State_fini_function(void * message_memory)
{
  message_interface__msg__State__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember message_interface__msg__State__rosidl_typesupport_introspection_c__State_message_member_array[1] = {
  {
    "statenum",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(message_interface__msg__State, statenum),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers message_interface__msg__State__rosidl_typesupport_introspection_c__State_message_members = {
  "message_interface__msg",  // message namespace
  "State",  // message name
  1,  // number of fields
  sizeof(message_interface__msg__State),
  message_interface__msg__State__rosidl_typesupport_introspection_c__State_message_member_array,  // message members
  message_interface__msg__State__rosidl_typesupport_introspection_c__State_init_function,  // function to initialize message memory (memory has to be allocated)
  message_interface__msg__State__rosidl_typesupport_introspection_c__State_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t message_interface__msg__State__rosidl_typesupport_introspection_c__State_message_type_support_handle = {
  0,
  &message_interface__msg__State__rosidl_typesupport_introspection_c__State_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_message_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, message_interface, msg, State)() {
  if (!message_interface__msg__State__rosidl_typesupport_introspection_c__State_message_type_support_handle.typesupport_identifier) {
    message_interface__msg__State__rosidl_typesupport_introspection_c__State_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &message_interface__msg__State__rosidl_typesupport_introspection_c__State_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
