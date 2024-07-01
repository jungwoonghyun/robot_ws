#include <chrono>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <errno.h>
#include <linux/types.h>
#include <math.h>
#include <functional>
#include <memory>
#include <string>
#include <ctime>

#include "rs485_settings.hpp"

// keyboard function 을 받아오기 위한 헤더파일
#include "keyboard_setting_function.hpp"

// Odometry 좌표상의 로봇 기구학 계산을 보다 쉽게 하기 위하여,
// ROS2 에서 기본적으로 제공하는 geometry_msgs/msg/twist 를 사용하기 위한 헤더 파일
#include "geometry_msgs/msg/twist.hpp"

// Node 클래스를 사용하기 위한 rclcpp 헤더 파일
#include "rclcpp/rclcpp.hpp"

#include "message_interface/msg/iscoast.hpp"

// bind 함수의 대체자 역할을 위해 _1로 선언
using std::placeholders::_1;
    char ch;
// Math.h 의 변수 사용을 위한 매크로
#define _USE_MATH_DEFINES

// RS485 통신을 위한 데이터 - 시작 -
#define MOTION_CMD_BUFFER_SIZE_MAIN  256

COMM_HANDLE hComm;

static char *pszDevName = "/dev/ttySerial";
static const int nBaud = 2000000;
// RS485 통신을 위한 데이터 - 종료 -

// Parameter 데이터를 위한 변수
double step_p_rot;
double wheel_dia;
double m_cir_dia;

bool coast_state = false;
bool before_coast = false;

// rclcpp의 Node클래스를 상속하여 사용
class PacketRS485Subscriber : public rclcpp::Node
{
public:
  // Node 클래스의 생성자를 호출하고 노드 이름을 packet_RS485_subscriber 지정
  PacketRS485Subscriber()
  : Node("packet_RS485_subscriber")
  {
    // Parameter를 불러오기 위한 선언 및 초기화(Rooty 모델 기준 초기화)
    this->declare_parameter("step_per_rotate", 120.0);
    this->declare_parameter("wheel_diameter", 0.254);
    this->declare_parameter("motion_circle_diameter", 0.480);

    // QoS depth 10으로 하여 버퍼에 10개 저장
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    // 구독할 토픽의 메시지 타입과 토픽의 이름, QoS 설정, 수신받은 메시지를 처리할 콜백함수를 기입
    packet_RS485_subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "cmd_vel",
      qos_profile,
      std::bind(&PacketRS485Subscriber::subscribe_topic_message, this, _1));

    is_motor_coast_ = this->create_subscription<message_interface::msg::Iscoast>(
      "is_coast",
      qos_profile,
      std::bind(&PacketRS485Subscriber::motor_coast_val, this, _1));
  }

private:

  void motor_coast_val(const message_interface::msg::Iscoast & msg) const
  {
    coast_state = msg.iscoast;
    // std::cout << "coast state: " << coast_state <<" iscoast: " << msg.iscoast << std::endl;
  }

  // 콜백함수
  void subscribe_topic_message(const geometry_msgs::msg::Twist::SharedPtr msg) const
  {
    // 계산을 위한 변수 선언
    double angular_, linear_;
    double spd_right, spd_left;
    double scale_linear, scale_angular;

    /*****************************************

       |---m_cir_dia---|

      ******************* -
      * *             * * | wheel_dia
      * *             * * |
      ***             *** -
        *             *
        *             *
        *             *
        *             *
        *             *
        ***************

    1) about linear_x
    1 step_p_rot = 60 rpm = 1 rps
    1 rps = (Jinuxing Motor) wheel_dia * M_PI m/s

    2) about angular_z
    distance between Motors : m_cir_dia mm
    wheel speed (1 rps) : wheel_dia * pi mm/s
    if robot rotate : pi rad/s, wheel rotate : m_cir_dia / (2 * wheel_dia) rps


    linear speed(m/s) : step_p_rot(sps) * (1.0 / (wheel_dia * M_PI)) * linear_x
    angular speed(rad/s) : angular_z * m_cir_dia/(2 * wheel_dia * pi)

    *****************************************/

    // 저장된 Parameter 데이터 로딩
    step_p_rot = this->get_parameter("step_per_rotate").get_value<double>();
    wheel_dia = this->get_parameter("wheel_diameter").get_value<double>();
    m_cir_dia = this->get_parameter("motion_circle_diameter").get_value<double>();

    // Publisher 로부터 읽어들인 데이터를 변수에 저장한 후 출력
    scale_linear = step_p_rot * (1.0 / (wheel_dia * M_PI));
    scale_angular = scale_linear * (m_cir_dia / (wheel_dia * 2.0 * M_PI));
    angular_ = msg->angular.z; // rad/s
    linear_ = msg->linear.x; // m/s
    RCLCPP_INFO(this->get_logger(), "Subscribed message: %.2f %.2f", angular_, linear_);
    // RCLCPP_INFO(this->get_logger(), "Parameter: '%.2f', '%.2f', '%.3f'", step_p_rot, wheel_dia, m_cir_dia);

    spd_right = scale_linear * linear_ + scale_angular * angular_; // M_PI;
    spd_left = scale_linear * linear_ - scale_angular * angular_; // M_PI;

    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
    std::tm now_tm = *std::localtime(&now_time_t);

    // 읽은 message 데이터에 대한 RS485 명령 수행
    if(coast_state == true)
    {
      if(coast_state != before_coast)
      {
        format_motion_command(hComm, "COAST");
        before_coast = coast_state;
        std::cout <<"coast\n";
      }
    }
    else
    {
      if(coast_state != before_coast)
      {
        format_motion_command(hComm, "SPEED@1=%d;SPEED@2=%d;START=SS", (int)spd_right, (int)spd_left);
      }
      else
      {   
        format_motion_command(hComm, "SPEED@1=%d;SPEED@2=%d", (int)spd_right, (int)spd_left);
      }
      before_coast = coast_state;
      // std::cout << "linear_," << linear_ << std::put_time(&now_tm, ",%Y-%m-%d %H %M %S,") << std::setw(3) << std::setfill('0') << now_ms.count() << "\n";
    }

    std::cout << "coast state: " << coast_state <<" before coast: " << before_coast << std::endl;

    msleep(15);
  }

  // private 변수로 사용되는 packet_RS485_subscriber_ 선언
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr packet_RS485_subscriber_;
  rclcpp::Subscription<message_interface::msg::Iscoast>::SharedPtr is_motor_coast_;
};

int main(int argc, char * argv[])
{
  hComm = open_comm_dev(pszDevName, nBaud);
  start_robot(hComm);

  rclcpp::init(argc, argv);
  auto node = std::make_shared<PacketRS485Subscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  end_robot(hComm);
  close_comm_dev(hComm);

  return 0;
}
