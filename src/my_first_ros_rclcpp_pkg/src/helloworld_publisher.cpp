#include <chrono>
#include <functional>
#include <memory>
#include <string>

// Node 클래스를 사용하기 위한 rclcpp 헤더 파일
#include "rclcpp/rclcpp.hpp"

// 메시지 타입인 String 선언
#include "std_msgs/msg/string.hpp"

// 추후 500ms, 1s 와 같이 시간을 가시성 있게 문자로 표현하기 위한 namespace
using namespace std::chrono_literals;

// rclcpp의 Node 클래스를 상속하여 사용
class HelloworldPublisher : public rclcpp::Node
{
public:
  // Node 클래스의 생성자를 호출, 노드 이름을 helloworld_publisher로 지정, count_는 0으로 초기화
  HelloworldPublisher()
  : Node("helloworld_publisher"), count_(0)
  {
    //  QoS 설정을 위해 KeepLast 형태로 depth를 10으로 설정하여 퍼블리시할 데이터를 버퍼에 10개까지 저장
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    // node클래스의 create_publisher함수를 이용하여 퍼블리셔 설정, 메시지 타입으로 String, 토픽 이름으로 helloworld, QoS
    helloworld_publisher_ = this->create_publisher<std_msgs::msg::String>(
      "helloworld", qos_profile);

    // 콜백 함수를 수행, period=1초, 1초마다 지정한 콜백함수를 실행
    timer_ = this->create_wall_timer(
      1s, std::bind(&HelloworldPublisher::publish_helloworld_msg, this));
  }

private:
  // 콜백 함수
  void publish_helloworld_msg()
  {
    // String 타입으로 msg 선언
    auto msg = std_msgs::msg::String();

    // 메시지 데이터를 입력
    msg.data = "Hello World: " + std::to_string(count_++);

    // logging, RCLCPP_XXX 계열의 함수는 print와 비슷
    RCLCPP_INFO(this->get_logger(), "Published message: '%s'", msg.data.c_str());

    // publishing
    helloworld_publisher_->publish(msg);
  }

  // private 변수
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr helloworld_publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  // rclcpp 초기화
  rclcpp::init(argc, argv);

  // 클래스 생성
  auto node = std::make_shared<HelloworldPublisher>();

  // 콜백 함수 실행
  rclcpp::spin(node);

  // ctrl+c와 같은 인터럽트 시그널 예외 상황에서 노드 종료
  rclcpp::shutdown();
  return 0;
}
