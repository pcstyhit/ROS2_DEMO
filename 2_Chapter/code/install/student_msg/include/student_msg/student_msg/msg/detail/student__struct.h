// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from student_msg:msg/Student.idl
// generated code does not contain a copyright notice

#ifndef STUDENT_MSG__MSG__DETAIL__STUDENT__STRUCT_H_
#define STUDENT_MSG__MSG__DETAIL__STUDENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Student in the package student_msg.
typedef struct student_msg__msg__Student
{
  rosidl_runtime_c__String name;
  int32_t exam;
  double score;
} student_msg__msg__Student;

// Struct for a sequence of student_msg__msg__Student.
typedef struct student_msg__msg__Student__Sequence
{
  student_msg__msg__Student * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} student_msg__msg__Student__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STUDENT_MSG__MSG__DETAIL__STUDENT__STRUCT_H_
