import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import xacro

def generate_launch_description():
    package_name = 'urdf_tutorial'

    # robot_state_publisher
    pkg_path = os.path.join(get_package_share_directory(package_name))
    xacro_file = os.path.join(pkg_path, 'urdf', 'robot_3.xacro')
    robot_description = xacro.process_file(xacro_file)
    params = {'robot_description': robot_description.toxml(), 'use_sim_time': False}

    rsp = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params],
    )

    # fake driver
    fake_driver = Node(
        package='urdf_tutorial',
        executable='fake_driver',
        output='screen',
        parameters=[],
    )

    # odometry publisher
    odometry_publisher = Node(
        package='car_odom',
        executable='car_odom',
        output='screen',
        parameters=[],
    )

    # rviz2
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', 'robot_ws/src/urdf_tutorial/config/robot_joint.rviz'],
    )
    
    safeway_sub = Node(
        package='safeway_robot_controll_packet_rs485',
        executable='packet_rs485_subscriber',
        output='screen',
        parameters=[],
    )

    safeway_sub_wagon = Node(
        package='safeway_robot_controll_packet_rs485',
        executable='packet_rs485_subscriber_wagon',
        output='screen',
        parameters=[],
    )

    safeway_esp = Node(
        package='safeway_robot_controll_packet_rs485',
        executable='ESP32_controller',
        output='screen',
        parameters=[],
    )

    return LaunchDescription(
        [
            rsp,
            fake_driver,
            odometry_publisher,
            #safeway_sub,
            rviz,
            # safeway_sub_wagon,
            # safeway_esp,
        ]
    )
