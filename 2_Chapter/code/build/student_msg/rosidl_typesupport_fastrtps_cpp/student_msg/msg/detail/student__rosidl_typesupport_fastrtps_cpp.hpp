// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from student_msg:msg/Student.idl
// generated code does not contain a copyright notice

#ifndef STUDENT_MSG__MSG__DETAIL__STUDENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define STUDENT_MSG__MSG__DETAIL__STUDENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "student_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "student_msg/msg/detail/student__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace student_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_student_msg
cdr_serialize(
  const student_msg::msg::Student & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_student_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  student_msg::msg::Student & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_student_msg
get_serialized_size(
  const student_msg::msg::Student & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_student_msg
max_serialized_size_Student(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace student_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_student_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, student_msg, msg, Student)();

#ifdef __cplusplus
}
#endif

#endif  // STUDENT_MSG__MSG__DETAIL__STUDENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
