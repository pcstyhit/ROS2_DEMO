from setuptools import setup

# 项目包名
package_name = 'vscodePythonDemo'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    # 依赖的打包工具
    install_requires=['setuptools'],
    zip_safe=True,
    # 项目用户信息
    maintainer='pldz',
    maintainer_email='pldz@R7000.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            # 可执行文件的入口
            'vscodePythonDemoNode = vscodePythonDemo.vscodePythonDemoNode:main'
        ],
    },
)
