import sys
import rclpy
from rclpy.node import Node
# 1. 导入包
from srv_demo.srv import AddInt

# 2.定义客户端节点
class pythonSrvClient(Node):

    def __init__(self):
        # 2.1 继承node节点，节点名为pythonSrvClientNode
        super().__init__('pythonSrvClientNode')
        # 2.2 创建客户端
        self.client_ = self.create_client(AddInt, 'mySrvName')
        # 2.3 等待连接
        self.wait_for_connect()


    # 3. 实现等待函数
    def wait_for_connect(self):
        while not self.client_.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for connect ...')

    # 4. 实现发送请求函数
    def send_request(self, num1, num2):
        request = AddInt.Request()
        request.num1 = num1
        request.num2 = num2
        self.future = self.client_.call_async(request)


def main():
    rclpy.init()
    # 5.创建客户端节点
    pythonSrvClientNode = pythonSrvClient()
    pythonSrvClientNode.send_request(200,300)

    # 6. 等待响应
    rclpy.spin_until_future_complete(pythonSrvClientNode,pythonSrvClientNode.future)
    try:
        response = pythonSrvClientNode.future.result()
    except Exception as e:
        pythonSrvClientNode.get_logger().info('Request error  {}'.format(e))
    else:
        pythonSrvClientNode.get_logger().info(
            'Response is {}'.format(response.sum))

    rclpy.shutdown()


if __name__ == '__main__':
    main()