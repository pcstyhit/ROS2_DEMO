// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from srv_demo:srv/AddInt.idl
// generated code does not contain a copyright notice

#ifndef SRV_DEMO__SRV__DETAIL__ADD_INT__BUILDER_HPP_
#define SRV_DEMO__SRV__DETAIL__ADD_INT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "srv_demo/srv/detail/add_int__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace srv_demo
{

namespace srv
{

namespace builder
{

class Init_AddInt_Request_num2
{
public:
  explicit Init_AddInt_Request_num2(::srv_demo::srv::AddInt_Request & msg)
  : msg_(msg)
  {}
  ::srv_demo::srv::AddInt_Request num2(::srv_demo::srv::AddInt_Request::_num2_type arg)
  {
    msg_.num2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::srv_demo::srv::AddInt_Request msg_;
};

class Init_AddInt_Request_num1
{
public:
  Init_AddInt_Request_num1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddInt_Request_num2 num1(::srv_demo::srv::AddInt_Request::_num1_type arg)
  {
    msg_.num1 = std::move(arg);
    return Init_AddInt_Request_num2(msg_);
  }

private:
  ::srv_demo::srv::AddInt_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::srv_demo::srv::AddInt_Request>()
{
  return srv_demo::srv::builder::Init_AddInt_Request_num1();
}

}  // namespace srv_demo


namespace srv_demo
{

namespace srv
{

namespace builder
{

class Init_AddInt_Response_sum
{
public:
  Init_AddInt_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::srv_demo::srv::AddInt_Response sum(::srv_demo::srv::AddInt_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::srv_demo::srv::AddInt_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::srv_demo::srv::AddInt_Response>()
{
  return srv_demo::srv::builder::Init_AddInt_Response_sum();
}

}  // namespace srv_demo

#endif  // SRV_DEMO__SRV__DETAIL__ADD_INT__BUILDER_HPP_
