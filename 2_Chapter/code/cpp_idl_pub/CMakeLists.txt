cmake_minimum_required(VERSION 3.8)
project(cpp_idl_pub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# 1. 添加依赖项
find_package(rclcpp REQUIRED)
find_package(student_msg REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# 2. 默认是已经创建了构建节点的文件配置
add_executable(cppIdlPubNode src/cppIdlPubNode.cpp)

# 3. 默认已经包括<INSTALL_INTERFACE>的路径也不用更改
target_include_directories(cppIdlPubNode PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)


# 4. ament工具构建节点的依赖配置
ament_target_dependencies(
  cppIdlPubNode
  rclcpp
  student_msg
)

target_compile_features(cppIdlPubNode PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

# 5. Install配置，默认ros2 run <包名>的配置
install(TARGETS cppIdlPubNode
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# 6. 生成包的环境
ament_package()
