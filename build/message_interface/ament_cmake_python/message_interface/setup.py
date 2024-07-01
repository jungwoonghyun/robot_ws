from setuptools import find_packages
from setuptools import setup

setup(
    name='message_interface',
    version='0.0.0',
    packages=find_packages(
        include=('message_interface', 'message_interface.*')),
)
