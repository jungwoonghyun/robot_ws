#include "esp32_init.hpp"

// Node 클래스를 사용하기 위한 rclcpp 헤더 파일
#include "rclcpp/rclcpp.hpp"
#include "message_interface/msg/mode.hpp"
#include "message_interface/msg/state.hpp"

// bind 함수의 대체자 역할을 위해 _1로 선언
using std::placeholders::_1;

// 추후 500ms, 1s 와 같이 시간을 가시성 있게 문자로 표현하기 위한 namespace
using namespace std::chrono_literals;

static char * esp32Uart = "/dev/ttyESP";
int fd;
uint8_t buf[1];
uint8_t bef_buf = 0;
uint8_t selector[1] = {0};
uint8_t selector_bef = 1;
 
class PacketESP32Controller : public rclcpp::Node
{
public:
  // Node 클래스의 생성자를 호출, 노드 이름을 packet_RS485_publisher 지정, count_는 0으로 초기화
  PacketESP32Controller()
  : Node("esp32_controller")
  {
    //  QoS 설정을 위해 KeepLast 형태로 depth를 10으로 설정하여 퍼블리시할 데이터를 버퍼에 10개까지 저장
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    packet_ESP32_Subscriber_ = this->create_subscription<message_interface::msg::State>(
      "mode_selector_sub",
      qos_profile,
      std::bind(&PacketESP32Controller::state_message, this, _1));

    // node클래스의 create_publisher함수를 이용하여 퍼블리셔 설정
    packet_ESP32_Publisher_ = this->create_publisher<message_interface::msg::Mode>(
      "mode_selector_pub", qos_profile);

    // 콜백 함수를 수행, 지정한 시간마다 지정한 콜백함수를 실행
    timer_ = this->create_wall_timer(
      100ms, std::bind(&PacketESP32Controller::esp32_msg, this));
  }

private:

  void esp32_msg()
  {
    message_interface::msg::Mode c_mode;
    
    Esp32ReadData(&fd, &buf[0]);
    usleep(1000);
    Esp32WriteData(&fd, &selector[0]);

    c_mode.modenum = (int)buf[0];

    // Esp32WriteData(&fd, &selector[0]);

    RCLCPP_INFO(this->get_logger(), "Receive %d mode num from ESP32\r\n", c_mode.modenum);
    packet_ESP32_Publisher_->publish(c_mode);
  }

  void state_message(const message_interface::msg::State & msg) const
  {
    
    selector[0] = (uint8_t)msg.statenum;


    RCLCPP_INFO(this->get_logger(), "Receive %d mode num from PC, Change\r\n", selector[0]);
  }

  // private 변수
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<message_interface::msg::Mode>::SharedPtr packet_ESP32_Publisher_;
  rclcpp::Subscription<message_interface::msg::State>::SharedPtr packet_ESP32_Subscriber_;
  //size_t count_;
};

int main(int argc, char * argv[])
{
  // rclcpp 초기화
  rclcpp::init(argc, argv);

  openEsp32Device(esp32Uart,&fd);

  // 클래스 생성
  auto node = std::make_shared<PacketESP32Controller>();

  // 콜백 함수 실행
  rclcpp::spin(node);

  // ctrl+c와 같은 인터럽트 시그널 예외 상황에서 노드 종료
  rclcpp::shutdown();

  return 0;
}
