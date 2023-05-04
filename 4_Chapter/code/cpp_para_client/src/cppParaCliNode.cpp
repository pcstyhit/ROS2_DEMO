// 1.包含头文件；
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

// 2.定义节点类；
class CppParaClient : public rclcpp::Node
{
public:
  CppParaClient() : Node("cppParaCliNode")
  {
    // 2.1 连接到节点参数的服务节点,注意此时的第二个参数是连接的服务端节点名
    paramClient = std::make_shared<rclcpp::SyncParametersClient>(this, "cppParamSerNode");
  }

  // 3. 连接服务函数
  bool connect_server()
  {
    // 3.1 等待服务连接
    while (!paramClient->wait_for_service(1s))
    {
      if (!rclcpp::ok())
      {
        return false;
      }
      RCLCPP_INFO(this->get_logger(), "The server connect failed! ");
    }

    return true;
  }

  // 4. 查询参数
  void get_values()
  {
    RCLCPP_INFO(this->get_logger(), "----------- Get the values -----------");
    auto params = paramClient->get_parameters({"name", "height"});
    for (auto &param : params)
    {
      RCLCPP_INFO(this->get_logger(), "%s = %s", param.get_name().c_str(), param.value_to_string().c_str());
    }
  }

  // 5. 修改参数
  void update_param()
  {
    RCLCPP_INFO(this->get_logger(), "----------- Change the values -----------");
    paramClient->set_parameters({rclcpp::Parameter("name", "lisi"),
                                 // 这是服务端不存在的参数，只有服务端设置了rclcpp::NodeOptions().allow_undeclared_parameters(true)时，
                                 //  这个参数才会被成功设置。
                                 rclcpp::Parameter("sex", "man")});
  }

private:
  rclcpp::SyncParametersClient::SharedPtr paramClient;
};

int main(int argc, char const *argv[])
{
  rclcpp::init(argc, argv);

  // 4.创建节点对象指针，调用参数操作函数；
  auto paramClient = std::make_shared<CppParaClient>();
  bool flag = paramClient->connect_server();
  if (!flag)
  {
    return 0;
  }
  paramClient->get_values();
  paramClient->update_param();
  paramClient->get_values();

  // 5.释放资源。
  rclcpp::shutdown();
  return 0;
}