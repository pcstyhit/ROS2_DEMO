# 1. 导入包
import rclpy
from rclpy.node import Node
from rcl_interfaces.srv import ListParameters
from rcl_interfaces.srv import GetParameters
from rcl_interfaces.srv import SetParameters
from rcl_interfaces.msg import ParameterType
from rcl_interfaces.msg import Parameter
from rcl_interfaces.msg import ParameterValue
from ros2param.api import get_parameter_value

# 2 创建客户节点
class PythonParaClient(Node):
    # 2.1 构造函数
    def __init__(self):
        super().__init__('pythonParaCliNode')

    # 3 连接服务节点
    def list_params(self):
        # 3.1 创建客户端；
        cli_list = self.create_client(ListParameters, '/pythonParaSerNode/list_parameters')
        # 3.2 等待服务连接；
        while not cli_list.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for connect ...')
        req = ListParameters.Request()
        future = cli_list.call_async(req)
        rclpy.spin_until_future_complete(self,future)
        return future.result()

    # 4 获得所有参数
    def get_params(self,names):
        # 4.1 创建客户端
        cli_get = self.create_client(GetParameters, '/pythonParaSerNode/get_parameters')
        # 4.2 等待服务连接
        while not cli_get.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for connect ...')
        req = GetParameters.Request()
        req.names = names
        future = cli_get.call_async(req)
        rclpy.spin_until_future_complete(self,future)
        return future.result()

    # 5 更新参数服务值
    def set_params(self):
        # 5.1 创建客户端
        cli_set = self.create_client(SetParameters, '/pythonParaSerNode/set_parameters')
        # 5.2 等待服务连接
        while not cli_set.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for connect ...')

        req = SetParameters.Request()

        p1 = Parameter()
        p1.name = "name"
        p1.value = get_parameter_value(string_value="zhangsan")

        req.parameters = [p1]
        future = cli_set.call_async(req)
        rclpy.spin_until_future_complete(self,future)
        return future.result()

def main():
    rclpy.init()
    client = PythonParaClient()

    # 获取参数列表
    client.get_logger().info("--------- List all parameters node ---------")
    response = client.list_params()
    for name in response.result.names:
        client.get_logger().info(name)

    client.get_logger().info("--------- Get ---------")
    names = ["name","height"]
    response = client.get_params(names)
    print(response.values)

    client.get_logger().info("--------- Set ---------")
    response = client.set_params()
    results = response.results
    response = client.get_params(names)
    print(response.values)
    rclpy.shutdown()

if __name__ == "__main__":
    main()