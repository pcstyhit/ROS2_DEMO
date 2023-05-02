from setuptools import find_packages
from setuptools import setup

setup(
    name='student_msg',
    version='0.0.0',
    packages=find_packages(
        include=('student_msg', 'student_msg.*')),
)
