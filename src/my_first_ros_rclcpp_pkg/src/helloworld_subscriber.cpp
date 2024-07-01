#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// bind 함수의 대체자 역할을 위해 _1로 선언
using std::placeholders::_1;

// rclcpp의 Node클래스를 상속하여 사용
class HelloworldSubscriber : public rclcpp::Node
{
public:
  // Node 클래스의 생성자를 호출하고 노드 이름을 helloworld_subscriber로 지정
  HelloworldSubscriber()
  : Node("Helloworld_subscriber")
  {
    // QoS depth 10으로 하여 버퍼에 10개 저장
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    // 구독할 토픽의 메시지 타입과 토픽의 이름, QoS 설정, 수신받은 메시지를 처리할 콜백함수를 기입
    helloworld_subscriber_ = this->create_subscription<std_msgs::msg::String>(
      "helloworld",
      qos_profile,
      std::bind(&HelloworldSubscriber::subscribe_topic_message, this, _1));
  }

private:
  // 콜백함수
  void subscribe_topic_message(const std_msgs::msg::String::SharedPtr msg) const
  {
    // logging
    RCLCPP_INFO(this->get_logger(), "Received message: '%s'", msg->data.c_str());
  }

  // private 변수로 사용되는 helloworld_subscriber_ 선언
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr helloworld_subscriber_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<HelloworldSubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
