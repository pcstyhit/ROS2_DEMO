from setuptools import setup

package_name = 'python_idl_pub'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='pldz',
    maintainer_email='pldz@R7000.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    # 配置节点的main函数入口
    entry_points={
        'console_scripts': [
            'pythonIdlPubNode = python_idl_pub.pythonIdlPubNode:main'
        ],
    },
)
