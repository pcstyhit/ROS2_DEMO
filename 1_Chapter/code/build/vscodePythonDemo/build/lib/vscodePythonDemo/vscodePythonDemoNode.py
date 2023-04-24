import rclpy
from rclpy.node import Node

# 继承Node类，定义VSCodePythonDemo类
class VSCodePythonDemo(Node):
    # 初始化Python构造函数
    def __init__(self, nodeName:str):
        super().__init__(nodeName)
    
    def printHello(self):
        self.get_logger().info("hello world!")

def main():
    rclpy.init()
    # 创建VSCodePythonDemo对象
    node = VSCodePythonDemo("vscodePythonDemo")
    # 调用成员函数
    node.printHello()
    rclpy.shutdown()