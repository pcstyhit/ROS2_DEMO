#include "rclcpp/rclcpp.hpp"

// 1. 添加自定义消息头文件，如果vscode出现下划线警告，则需要配置settings.json添加include路径
#include "student_msg/msg/student.hpp"

// 占位符，结合std::bind函数的绑定使用
using std::placeholders::_1;

// 2. 引入Student.msg生成的Student类
using student_msg::msg::Student;

class CppIdlMsgSub: public rclcpp::Node
{
  public:
      /* 3. ROS2节点的构造函数，其中包括一个node对象（初始化时候没有给出节点的名称），
      * 和属性exam_（初始化为0,类型为size_t)，以及属性socre_（类型为double_t初始值为60.0） */
      CppIdlMsgSub(const char* nodeName):Node(nodeName)
      {
      subscription_ = this->create_subscription<Student>(
      "myStudent", 10, std::bind(&CppIdlMsgSub::topic_callback, this, _1));
      }

  private:
    // 4. 定义订阅到消息的回调函数
    void topic_callback(const Student & stu) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: %s, exam: %d, score: %f", stu.name.c_str(),stu.exam, stu.score);
    }

    // 5. 计时器、发布者和计数器字段的声明
    rclcpp::Subscription<Student>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // 创建节点，给出构造的节点名为CppIdlMsgSubNode
  rclcpp::spin(std::make_shared<CppIdlMsgSub>("CppIdlMsgSubNode"));
  rclcpp::shutdown();
  return 0;
}
