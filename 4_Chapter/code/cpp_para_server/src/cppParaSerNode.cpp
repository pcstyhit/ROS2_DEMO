// 1. 生成节点的头文件
#include "rclcpp/rclcpp.hpp"

// 2. 定义节点参数服务端
class CppParamServer : public rclcpp::Node
{
public:
  // 2.1 构造函数，设置节点名，以及允许被删除的内容
  CppParamServer() : Node("cppParamSerNode",rclcpp::NodeOptions().allow_undeclared_parameters(true)) {}

  // 2.2 创建默认的参数表
  void declare_param()
  {
    // 2.2.1 声明参数并设置默认值
    this->declare_parameter("name", "zhangsan");
    this->declare_parameter("height", "1.8");

    // 2.2.2 未声明的参数，该参数可以被删除
    this->set_parameter(rclcpp::Parameter("age", "20"));
  }

  // 3 获取到现在的所有参数
  void get_AllValue()
  {
    RCLCPP_INFO(this->get_logger(), "------------------ Get the params ----------------");
    auto params = this->get_parameters({"name", "height", "age"});
    for (auto &param : params)
    {
      // 3.1 get_name函数获取参数名，value_to_string获取到参数的字符串值
      RCLCPP_INFO(this->get_logger(), "parameter is %s,  the value is %s", param.get_name().c_str(), param.value_to_string().c_str());
    }
  }

  // 4 修改参数
  void update_param()
  {
    RCLCPP_INFO(this->get_logger(), "------------------ Change the value  ----------------");
    this->set_parameter(rclcpp::Parameter("name", "lisi"));
    this->get_AllValue();
  }

  // 5. 删除参数
  void del_param()
  {
    RCLCPP_INFO(this->get_logger(), "------------------ Delete ----------------");
    // 5.1 删除只能删除未声明的参数，不能删除声明过的参数
    this->undeclare_parameter("age");
    auto params = this->get_parameters({"name", "height"});
    for (auto &param : params)
    {
      // 5.1 get_name函数获取参数名，value_to_string获取到参数的字符串值
      RCLCPP_INFO(this->get_logger(), "parameter is %s,  the value is %s", param.get_name().c_str(), param.value_to_string().c_str());
    }
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto paramServer = std::make_shared<CppParamServer>();
  // 执行对应的函数
  paramServer->declare_param();
  paramServer->get_AllValue();
  paramServer->update_param();
  paramServer->del_param();

  rclcpp::spin(paramServer);
  rclcpp::shutdown();
  return 0;
}