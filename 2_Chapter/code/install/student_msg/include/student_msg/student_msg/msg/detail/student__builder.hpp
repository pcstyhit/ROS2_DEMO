// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from student_msg:msg/Student.idl
// generated code does not contain a copyright notice

#ifndef STUDENT_MSG__MSG__DETAIL__STUDENT__BUILDER_HPP_
#define STUDENT_MSG__MSG__DETAIL__STUDENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "student_msg/msg/detail/student__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace student_msg
{

namespace msg
{

namespace builder
{

class Init_Student_score
{
public:
  explicit Init_Student_score(::student_msg::msg::Student & msg)
  : msg_(msg)
  {}
  ::student_msg::msg::Student score(::student_msg::msg::Student::_score_type arg)
  {
    msg_.score = std::move(arg);
    return std::move(msg_);
  }

private:
  ::student_msg::msg::Student msg_;
};

class Init_Student_exam
{
public:
  explicit Init_Student_exam(::student_msg::msg::Student & msg)
  : msg_(msg)
  {}
  Init_Student_score exam(::student_msg::msg::Student::_exam_type arg)
  {
    msg_.exam = std::move(arg);
    return Init_Student_score(msg_);
  }

private:
  ::student_msg::msg::Student msg_;
};

class Init_Student_name
{
public:
  Init_Student_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Student_exam name(::student_msg::msg::Student::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Student_exam(msg_);
  }

private:
  ::student_msg::msg::Student msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::student_msg::msg::Student>()
{
  return student_msg::msg::builder::Init_Student_name();
}

}  // namespace student_msg

#endif  // STUDENT_MSG__MSG__DETAIL__STUDENT__BUILDER_HPP_
