import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class PythonBaseMsgPub(Node):

    def __init__(self, nodeName):
        # 1. 初始化父类构造函数，其中节点名需要创建时候指定,计数属性count_从0开始
        super().__init__(nodeName)
        self.count_ = 0
        # 2. 声明发布者，发布消息类型为String，话题名为myTopicName,队列大小为10
        self.publisher_ = self.create_publisher(String, 'myTopicName', 10)
        # 3. 创建定时器，其中更新频率为0.5秒，并绑定回调函数
        self.timer = self.create_timer(0.5, self.timer_callback)
        
    # 4. 定义回调函数
    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.count_
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.count_ += 1


def main(args=None):
    rclpy.init(args=args)
    pythonBaseMsgPubNode = PythonBaseMsgPub("pythonBaseMsgPubNode")
    rclpy.spin(pythonBaseMsgPubNode)
    # 销毁节点
    pythonBaseMsgPubNode.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()