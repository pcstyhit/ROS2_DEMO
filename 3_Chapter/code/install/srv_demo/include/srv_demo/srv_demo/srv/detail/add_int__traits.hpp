// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from srv_demo:srv/AddInt.idl
// generated code does not contain a copyright notice

#ifndef SRV_DEMO__SRV__DETAIL__ADD_INT__TRAITS_HPP_
#define SRV_DEMO__SRV__DETAIL__ADD_INT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "srv_demo/srv/detail/add_int__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace srv_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddInt_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: num1
  {
    out << "num1: ";
    rosidl_generator_traits::value_to_yaml(msg.num1, out);
    out << ", ";
  }

  // member: num2
  {
    out << "num2: ";
    rosidl_generator_traits::value_to_yaml(msg.num2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddInt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: num1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num1: ";
    rosidl_generator_traits::value_to_yaml(msg.num1, out);
    out << "\n";
  }

  // member: num2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num2: ";
    rosidl_generator_traits::value_to_yaml(msg.num2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddInt_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace srv_demo

namespace rosidl_generator_traits
{

[[deprecated("use srv_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const srv_demo::srv::AddInt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  srv_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use srv_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const srv_demo::srv::AddInt_Request & msg)
{
  return srv_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<srv_demo::srv::AddInt_Request>()
{
  return "srv_demo::srv::AddInt_Request";
}

template<>
inline const char * name<srv_demo::srv::AddInt_Request>()
{
  return "srv_demo/srv/AddInt_Request";
}

template<>
struct has_fixed_size<srv_demo::srv::AddInt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<srv_demo::srv::AddInt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<srv_demo::srv::AddInt_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace srv_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddInt_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sum
  {
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddInt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddInt_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace srv_demo

namespace rosidl_generator_traits
{

[[deprecated("use srv_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const srv_demo::srv::AddInt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  srv_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use srv_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const srv_demo::srv::AddInt_Response & msg)
{
  return srv_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<srv_demo::srv::AddInt_Response>()
{
  return "srv_demo::srv::AddInt_Response";
}

template<>
inline const char * name<srv_demo::srv::AddInt_Response>()
{
  return "srv_demo/srv/AddInt_Response";
}

template<>
struct has_fixed_size<srv_demo::srv::AddInt_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<srv_demo::srv::AddInt_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<srv_demo::srv::AddInt_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<srv_demo::srv::AddInt>()
{
  return "srv_demo::srv::AddInt";
}

template<>
inline const char * name<srv_demo::srv::AddInt>()
{
  return "srv_demo/srv/AddInt";
}

template<>
struct has_fixed_size<srv_demo::srv::AddInt>
  : std::integral_constant<
    bool,
    has_fixed_size<srv_demo::srv::AddInt_Request>::value &&
    has_fixed_size<srv_demo::srv::AddInt_Response>::value
  >
{
};

template<>
struct has_bounded_size<srv_demo::srv::AddInt>
  : std::integral_constant<
    bool,
    has_bounded_size<srv_demo::srv::AddInt_Request>::value &&
    has_bounded_size<srv_demo::srv::AddInt_Response>::value
  >
{
};

template<>
struct is_service<srv_demo::srv::AddInt>
  : std::true_type
{
};

template<>
struct is_service_request<srv_demo::srv::AddInt_Request>
  : std::true_type
{
};

template<>
struct is_service_response<srv_demo::srv::AddInt_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SRV_DEMO__SRV__DETAIL__ADD_INT__TRAITS_HPP_
