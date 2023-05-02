// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from student_msg:msg/Student.idl
// generated code does not contain a copyright notice

#ifndef STUDENT_MSG__MSG__DETAIL__STUDENT__STRUCT_HPP_
#define STUDENT_MSG__MSG__DETAIL__STUDENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__student_msg__msg__Student __attribute__((deprecated))
#else
# define DEPRECATED__student_msg__msg__Student __declspec(deprecated)
#endif

namespace student_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Student_
{
  using Type = Student_<ContainerAllocator>;

  explicit Student_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->exam = 0l;
      this->score = 0.0;
    }
  }

  explicit Student_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->exam = 0l;
      this->score = 0.0;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _exam_type =
    int32_t;
  _exam_type exam;
  using _score_type =
    double;
  _score_type score;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__exam(
    const int32_t & _arg)
  {
    this->exam = _arg;
    return *this;
  }
  Type & set__score(
    const double & _arg)
  {
    this->score = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    student_msg::msg::Student_<ContainerAllocator> *;
  using ConstRawPtr =
    const student_msg::msg::Student_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<student_msg::msg::Student_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<student_msg::msg::Student_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      student_msg::msg::Student_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<student_msg::msg::Student_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      student_msg::msg::Student_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<student_msg::msg::Student_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<student_msg::msg::Student_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<student_msg::msg::Student_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__student_msg__msg__Student
    std::shared_ptr<student_msg::msg::Student_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__student_msg__msg__Student
    std::shared_ptr<student_msg::msg::Student_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Student_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->exam != other.exam) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    return true;
  }
  bool operator!=(const Student_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Student_

// alias to use template instance with default allocator
using Student =
  student_msg::msg::Student_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace student_msg

#endif  // STUDENT_MSG__MSG__DETAIL__STUDENT__STRUCT_HPP_
