import rclpy
from rclpy.node import Node

# 1. 导入包，其中的类名等于服务文件名称
from srv_demo.srv import AddInt

# 2. 定义服务端节点
class PythonSrvServer(Node):

    def __init__(self):
        super().__init__('pythonSrvServerNode')
        # 2.1 创建服务端
        self.srver_ = self.create_service(AddInt, 'mySrvName', self.addIntFunc)
        self.get_logger().info("Server is starting ...")

    # 2.2 服务端的处理回调函数
    def addIntFunc(self, request:AddInt, response:AddInt):
        response.sum = request.num1 + request.num2
        self.get_logger().info('The request is :{} {},Response is :{}'.format(request.num1, request.num2, response.sum))
        return response


def main():
    rclpy.init()
    pythonSrvServerNode = PythonSrvServer()
    rclpy.spin(pythonSrvServerNode)
    rclpy.shutdown()


if __name__ == '__main__':
    main()