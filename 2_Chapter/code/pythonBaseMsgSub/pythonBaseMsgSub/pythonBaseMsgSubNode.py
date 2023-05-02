import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class PythonBaseMsgSub(Node):

    def __init__(self, nodeName):
        # 1. 构造函数，初始化node节点
        super().__init__(nodeName)
        # 2. 声明订阅者，订阅话题`myTopicNmae`,并绑定回调函数
        self.subscription = self.create_subscription(String,'myTopicName',self.listener_callback,10)

    # 3. 定义回调函数
    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)
    pythonBaseMsgSubNode = PythonBaseMsgSub("pythonBaseMsgSubNode")
    rclpy.spin(pythonBaseMsgSubNode)
    pythonBaseMsgSubNode.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()