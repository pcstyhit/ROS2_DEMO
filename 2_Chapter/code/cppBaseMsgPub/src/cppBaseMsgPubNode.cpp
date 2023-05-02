#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// C++14中的时间库
using namespace std::chrono_literals;

class CppBaseMsgPub: public rclcpp::Node
{
  public:
      /* 1. ROS2节点的构造函数，其中包括一个node对象（初始化时候没有给出节点的名称），
      * 和属性count_(默认初始化为0) */
      CppBaseMsgPub(const char* nodeName):Node(nodeName), count_(0)
      {
        // 2. 创建发布者,参数分别为话题名称myTopicName，和发布队列的长队为10
        publisher_ = this->create_publisher<std_msgs::msg::String>("myTopicName", 10);
        // 3. 创建定时器，设置发布的频率，并绑定定时执行的事件，这里给到的是CppBaseMsgPub类的函数
        timer_ = this->create_wall_timer(500ms, std::bind(&CppBaseMsgPub::timer_callback, this));
      }

  private:
     // 4. 定义回调函数
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Hello, world! " + std::to_string(count_++);
      RCLCPP_INFO(this->get_logger(), "Cpp Publish: '%s'", message.data.c_str());
      publisher_->publish(message);
    }

    // 5. 计时器、发布者和计数器字段的声明
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // 创建节点，给出构造的节点名为cppBaseMsgPubNode
  rclcpp::spin(std::make_shared<CppBaseMsgPub>("cppBaseMsgPubNode"));
  rclcpp::shutdown();
  return 0;
}