cmake_minimum_required(VERSION 3.8)
project(cppBaseMsgPub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# 1. 添加依赖项列表
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 2. 生成节点的主函数入口和节点名称
add_executable(cppBaseMsgPubNode src/cppBaseMsgPubNode.cpp)


# 3. Include路径配置，这里其实没有用上，可以不用配置
target_include_directories(cppBaseMsgPubNode PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

# 4. ament工具的编译所需要的依赖
ament_target_dependencies(
  cppBaseMsgPubNode
  "rclcpp"
  "std_msgs"
)

# 5. 安装规则
install(TARGETS cppBaseMsgPubNode
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

# 6. 配置ament环境，生成功能包
ament_package()
