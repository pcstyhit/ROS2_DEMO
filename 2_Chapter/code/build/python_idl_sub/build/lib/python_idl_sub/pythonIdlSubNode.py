import rclpy
from rclpy.node import Node

# 1. 导入包，如果vscode下划线警告，则需要配置settings.json
from student_msg.msg import Student


class PythonIdlSub(Node):

    def __init__(self, nodeName):
        # 1. 构造函数，初始化node节点
        super().__init__(nodeName)
        # 2. 声明订阅者，订阅话题`myTopicNmae`,并绑定回调函数
        self.subscription = self.create_subscription(Student,'myStudent',self.listener_callback,10)

    # 3. 定义回调函数
    def listener_callback(self, stu:Student):
        self.get_logger().info('I heard: name:{}, exam:{}, score{}'.format(stu.name, stu.exam, stu.score))


def main(args=None):
    rclpy.init(args=args)
    pythonIdlSubNode = PythonIdlSub("pythonIdlSubNode")
    rclpy.spin(pythonIdlSubNode)
    pythonIdlSubNode.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()