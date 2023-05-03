// 1. 调用自定义的服务文件
// 1.1 rclcpp和srv_demo两个功能包的头文件
#include "rclcpp/rclcpp.hpp"
#include "srv_demo/srv/add_int.hpp"

// 1.2. 调用功能包下的自定义的服务，其中自定义的服务名已经变成了一个类名
using srv_demo::srv::AddInt;

// std_bind的占位符
using std::placeholders::_1;
using std::placeholders::_2;

// 2.定义节点类；
class CppSrvServer: public rclcpp::Node{
  public:
  // 2.1 构造函数，其中节点名直接赋予cppSrvServerNode
    CppSrvServer():Node("cppSrvServerNode"){
      // 2.2 创建服务端
      server_ = this->create_service<AddInt>("mySrvName",std::bind(&CppSrvServer::addIntFunc, this, _1, _2));
      RCLCPP_INFO(this->get_logger(),"Server is starting ...");
    }
  private:
    
    // 3. 服务端的回调函数实现，其中参数的写法区分主要在于类型，参数数量包括请求体req和响应体rsp
    void addIntFunc(const AddInt::Request::SharedPtr req, const AddInt::Response::SharedPtr rsp)
    {
      rsp->sum = req->num1 + req->num2;
      RCLCPP_INFO(this->get_logger(),"request body :(%d,%d), response is :%d", req->num1, req->num2, rsp->sum);
    }

    // 4 服务的声明
    rclcpp::Service<AddInt>::SharedPtr server_;
};

int main(int argc, char const *argv[])
{
  rclcpp::init(argc,argv);
  auto server_ = std::make_shared<CppSrvServer>();
  rclcpp::spin(server_);
  rclcpp::shutdown();
  return 0;
}
