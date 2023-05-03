// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from srv_demo:srv/AddInt.idl
// generated code does not contain a copyright notice

#ifndef SRV_DEMO__SRV__DETAIL__ADD_INT__STRUCT_H_
#define SRV_DEMO__SRV__DETAIL__ADD_INT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/AddInt in the package srv_demo.
typedef struct srv_demo__srv__AddInt_Request
{
  int32_t num1;
  int32_t num2;
} srv_demo__srv__AddInt_Request;

// Struct for a sequence of srv_demo__srv__AddInt_Request.
typedef struct srv_demo__srv__AddInt_Request__Sequence
{
  srv_demo__srv__AddInt_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} srv_demo__srv__AddInt_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AddInt in the package srv_demo.
typedef struct srv_demo__srv__AddInt_Response
{
  int32_t sum;
} srv_demo__srv__AddInt_Response;

// Struct for a sequence of srv_demo__srv__AddInt_Response.
typedef struct srv_demo__srv__AddInt_Response__Sequence
{
  srv_demo__srv__AddInt_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} srv_demo__srv__AddInt_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SRV_DEMO__SRV__DETAIL__ADD_INT__STRUCT_H_
