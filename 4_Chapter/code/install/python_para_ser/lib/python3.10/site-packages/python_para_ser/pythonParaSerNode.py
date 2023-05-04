# 1. 导入包
import rclpy
from rclpy.node import Node

# 2. 创建节点参数服务节点
class PythonParaServer(Node):
    def __init__(self):
        # 2.1 构造函数
        super().__init__("pythonParaSerNode",allow_undeclared_parameters=True)

    # 3 声明节点参数
    def declare_param(self):
        self.declare_parameter("name","zhangsan")
        self.declare_parameter("height",1.88)
        # 3.1 声明未声明的参数，可以被删除
        self.age = rclpy.Parameter("age",value = "20")
        self.set_parameters([self.age])

    # 4 查询参数
    def get_param(self):
        self.get_logger().info("---- Get ----")
        params = self.get_parameters(["name","height","age"])
        for param in params:
            self.get_logger().info("%s ---> %s" % (param.name, param.value))

    # 5 修改参数
    def update_param(self):
        self.get_logger().info("---- Change ---")
        self.set_parameters([rclpy.Parameter("name",value = "lisi")])
        self.get_param()

    # 6 删除参数
    def del_param(self):
        self.get_logger().info("---- Delete ---")
        self.undeclare_parameter("age")
        params = self.get_parameters(["name","height"])
        for param in params:
            self.get_logger().info("%s ---> %s" % (param.name, param.value))


def main():
    rclpy.init()
    param_server = PythonParaServer()

    param_server.declare_param()
    param_server.get_param()
    param_server.update_param()
    param_server.del_param()

    rclpy.spin(param_server)
    rclpy.shutdown()


if __name__ == "__main__":
    main()