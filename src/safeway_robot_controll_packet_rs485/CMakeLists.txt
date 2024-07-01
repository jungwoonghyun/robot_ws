cmake_minimum_required(VERSION 3.8)
project(safeway_robot_controll_packet_rs485)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(message_interface REQUIRED)


# Build
add_executable(packet_rs485_publisher src/packet_rs485_publisher.cpp src/keyboard_setting_function.cpp)
include_directories(include/)
ament_target_dependencies(packet_rs485_publisher rclcpp std_msgs geometry_msgs)

add_executable(packet_rs485_subscriber src/packet_rs485_subscriber.cpp src/rs485_comm.cpp src/rs485_send.cpp src/rs485_crc16.cpp)
include_directories(include/)
ament_target_dependencies(packet_rs485_subscriber rclcpp std_msgs geometry_msgs message_interface)

add_executable(packet_uwb_dwm1001_publisher src/packet_uwb_dwm1001_publisher.cpp src/uwb_setting.cpp)
include_directories(include/)
ament_target_dependencies(packet_uwb_dwm1001_publisher rclcpp std_msgs geometry_msgs)

add_executable(packet_tf2_tracing src/packet_tf2_tracing.cpp)
include_directories(include/)
ament_target_dependencies(packet_tf2_tracing rclcpp std_msgs geometry_msgs tf2 tf2_ros visualization_msgs)

add_executable(esp32_controller src/packet_esp32_controller.cpp src/esp32_comm.cpp)
include_directories(include/)
ament_target_dependencies(esp32_controller rclcpp std_msgs message_interface)

add_executable(packet_rs485_subscriber_wagon src/packet_rs485_subscriber_wagon.cpp src/rs485_comm.cpp src/rs485_recv.cpp src/rs485_send.cpp src/rs485_crc16.cpp)
include_directories(include/)
ament_target_dependencies(packet_rs485_subscriber_wagon rclcpp std_msgs geometry_msgs message_interface)

#target_link_libraries(packet_RS485_publisher PRIVATE m)

# Install
install(TARGETS
  packet_rs485_publisher
  packet_rs485_subscriber
  packet_uwb_dwm1001_publisher
  packet_tf2_tracing
  esp32_controller
  packet_rs485_subscriber_wagon
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  # set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  #  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
