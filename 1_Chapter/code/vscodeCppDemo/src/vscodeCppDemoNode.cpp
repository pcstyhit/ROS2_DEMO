#include "rclcpp/rclcpp.hpp"

// 继承ROS2的客户端节点
class VSCodeCppDemo: public rclcpp::Node{
public:
    // ROS2节点的构造函数
    VSCodeCppDemo(const char* nodeName):Node(nodeName){
        RCLCPP_INFO(this->get_logger(),"hello world!");
    }

};

int main(int argc, char *argv[])
{
    rclcpp::init(argc,argv);
    // 生成自定义的ROS2客户端对象, node是一个对象指针
    auto node = std::make_shared<VSCodeCppDemo>("vscodeCppDemoNode");
    rclcpp::shutdown();
    return 0;
}