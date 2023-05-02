import rclpy
from rclpy.node import Node

# 1. 导入包，如果vscode下划线警告，则需要配置settings.json
from student_msg.msg import Student


class PythonIdlPub(Node):

    def __init__(self, nodeName):
        # 1. 初始化父类构造函数，其中节点名需要创建时候指定
        super().__init__(nodeName)
        self.exam_ = 0
        self.score_ = 60.0
        # 2. 声明发布者，发布消息类型为Student，话题名为myStudent,队列大小为10
        self.publisher_ = self.create_publisher(Student, 'myStudent', 10)
        # 3. 创建定时器，其中更新频率为0.5秒，并绑定回调函数
        self.timer = self.create_timer(0.5, self.timer_callback)
        
    # 4. 定义回调函数
    def timer_callback(self):
        stu = Student()
        stu.name = "zhangsan"
        stu.exam = self.exam_
        stu.score = self.score_

        self.publisher_.publish(stu)
        self.get_logger().info('Publishing: name: {}, exam:{}, score:{}'.format(stu.name,stu.exam,stu.score))
        self.exam_ += 1
        self.score_ += 0.1


def main(args=None):
    rclpy.init(args=args)
    pythonIdlPubNode = PythonIdlPub("pythonIdlPubNode")
    rclpy.spin(pythonIdlPubNode)
    # 销毁节点
    pythonIdlPubNode.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()