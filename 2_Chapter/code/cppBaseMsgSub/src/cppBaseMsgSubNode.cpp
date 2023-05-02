#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// 占位符，结合std::bind函数的绑定使用
using std::placeholders::_1;

class CppBaseMsgSub: public rclcpp::Node
{
  public:
    /* 1. ROS2节点的构造函数 */
    CppBaseMsgSub(const char* nodeName):Node(nodeName)
    {
      // 2.声明订阅话题类型，并绑定回调函数
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "myTopicName", 10, std::bind(&CppBaseMsgSub::topic_callback, this, _1));
    }

  private:
    // 3. 定义订阅到消息的回调函数
    void topic_callback(const std_msgs::msg::String & msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    }

    // 4. 计时器、发布者和计数器字段的声明
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // 初始化订阅节点
  rclcpp::spin(std::make_shared<CppBaseMsgSub>("cppBaseMsgSubNode"));
  rclcpp::shutdown();
  return 0;
}
