#include "rclcpp/rclcpp.hpp"

// 1. 添加自定义消息头文件，如果vscode出现下划线警告，则需要配置settings.json添加include路径
#include "student_msg/msg/student.hpp"

// C++14中的时间库
using namespace std::chrono_literals;

// 2. 引入Student.msg生成的Student类
using student_msg::msg::Student;

class CppIdlMsgPub: public rclcpp::Node
{
  public:
      /* 3. ROS2节点的构造函数，其中包括一个node对象（初始化时候没有给出节点的名称），
      * 和属性exam_（初始化为0,类型为size_t)，以及属性socre_（类型为double_t初始值为60.0） */
      CppIdlMsgPub(const char* nodeName):Node(nodeName), exam_(0), score_(60.0)
      {
        // 4. 创建发布者,参数分别为话题名称myStudent，和发布队列的长队为10
        publisher_ = this->create_publisher<Student>("myStudent", 10);
        // 5. 创建定时器，设置发布的频率，并绑定定时执行的事件，这里给到的是CppIdlMsgPub类的函数
        timer_ = this->create_wall_timer(500ms, std::bind(&CppIdlMsgPub::timer_callback, this));
      }

  private:
     // 6. 定义回调函数
    void timer_callback()
    {
      Student stu = Student();
      // 6.1 姓名zhangsan
      stu.name = "zhangsan";
      // 6.2 考试次数递增
      stu.exam = exam_++;
      // 6.3 分数一直递增
      stu.score = score_;
      score_ += 0.1;
      
      RCLCPP_INFO(this->get_logger(), "Student: '%s', exam time: %d, socre is : %f", stu.name.c_str(),stu.exam,stu.score);
      publisher_->publish(stu);

      
    }

    // 5. 计时器、发布者和计数器字段的声明
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<Student>::SharedPtr publisher_;
    size_t exam_;
    double_t score_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // 创建节点，给出构造的节点名为CppIdlMsgPubNode
  rclcpp::spin(std::make_shared<CppIdlMsgPub>("CppIdlMsgPubNode"));
  rclcpp::shutdown();
  return 0;
}
