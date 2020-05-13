#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

#include <chrono>

rclcpp::Node::SharedPtr g_node = nullptr;

/* We do not recommend this style anymore, because composition of multiple
 * nodes in the same executable is not possible. Please see one of the subclass
 * examples for the "new" recommended styles. This example is only included
 * for completeness because it is similar to "classic" standalone ROS nodes. */

void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg)
{
  RCLCPP_INFO(g_node->get_logger(), "I heard: '%d'", msg->data.size());

  rclcpp::Time time_header(msg->header.stamp.sec, msg->header.stamp.nanosec);
  rclcpp::Time time_now = rclcpp::Clock().now();
  RCLCPP_INFO(g_node->get_logger(), "pub ros_TS(NSec): %lu",time_header.nanoseconds());
  RCLCPP_INFO(g_node->get_logger(), "sub ros_TS(NSec): %lu",time_now.nanoseconds());
  //RCLCPP_INFO(g_node->get_logger(), "diff ros_TS(Sec): %d",(time_now.nanoseconds() - time_header.nanoseconds()) / 1000000000);
  std::cout <<"diff time: " << (double)(time_now.nanoseconds() - time_header.nanoseconds()) / 1000000000<<std::endl;


}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  g_node = rclcpp::Node::make_shared("img_subscriber");
  auto subscription =
    g_node->create_subscription<sensor_msgs::msg::Image>("topic", 10, topic_callback);
  rclcpp::spin(g_node);
  rclcpp::shutdown();
  // TODO(clalancette): It would be better to remove both of these nullptr
  // assignments and let the destructors handle it, but we can't because of
  // https://github.com/eProsima/Fast-RTPS/issues/235 .  Once that is fixed
  // we should probably look at removing these two assignments.
  subscription = nullptr;
  g_node = nullptr;
  return 0;
}
