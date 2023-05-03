// 1. 调用自定义的服务文件
// 1.1 rclcpp和srv_demo两个功能包的头文件
#include "rclcpp/rclcpp.hpp"
#include "srv_demo/srv/add_int.hpp"

// 1.2. 调用功能包下的自定义的服务，其中自定义的服务名已经变成了一个类名
using srv_demo::srv::AddInt;

// 时间函数用于持续访问服务端
using namespace std::chrono_literals;

// 2.定义节点类；
class CppSrvClient: public rclcpp::Node{
  public:
    CppSrvClient():Node("cppSrvClientNode")
    {
      // 2.1 创建客户端,并绑定服务通讯名称为mySrvName
      client_ = this->create_client<AddInt>("mySrvName");
      RCLCPP_INFO(this->get_logger(),"Client is starting  ...");
    }
    // 2.2 等待与服务的连接
    bool connect_server(){
      while (!client_->wait_for_service(1s))
      {
        if (!rclcpp::ok())
        {
          RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Interrupted while waiting for the service. Exiting.");
          return false;
        }

        RCLCPP_INFO(this->get_logger(),"service not available, waiting again...");
      }
      return true;
    }
    // 2.3 客户端发送请求；
    rclcpp::Client<srv_demo::srv::AddInt>::FutureAndRequestId send_request(int32_t num1, int32_t num2)
    {
      auto request = std::make_shared<AddInt::Request>();
      request->num1 = num1;
      request->num2 = num2;
      // 2.3.1 发送请求
      auto response = client_->async_send_request(request);
      return response;
    }

  private:
    // 2.4 服务通讯客户端的声明
    rclcpp::Client<AddInt>::SharedPtr client_;
};


int main(int argc, char ** argv)
{
  // 3. 初始化ROS2客户端
  rclcpp::init(argc,argv);

  // 3.1 创建对象指针并调用其功能；
  auto cppSrvClientNode = std::make_shared<CppSrvClient>();
  // 3.2 连接客户端
  bool flag = cppSrvClientNode->connect_server();
  if (!flag)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Connect failed! ");
    return 0;
  }

  // 3.3 发送请求并等待响应
  auto response = cppSrvClientNode->send_request(100,200);

   // 3.4 节点处理响应
  if (rclcpp::spin_until_future_complete(cppSrvClientNode,response) == rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(cppSrvClientNode->get_logger(),"The response is :%d!", response.get()->sum);

  } else {
    RCLCPP_INFO(cppSrvClientNode->get_logger(),"Request error");
  }
  rclcpp::shutdown();
  return 0;
}