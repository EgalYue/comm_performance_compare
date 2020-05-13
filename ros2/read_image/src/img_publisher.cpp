#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <rclcpp/clock.hpp>

#include <chrono>
#include <algorithm>
#include <random>
#include <functional>
#include <climits>

using random_bytes_engine = std::independent_bits_engine<std::default_random_engine, CHAR_BIT, unsigned char>;

int main(int argc, char** argv)
{
    
    if(argc < 2){
        std::cout<< "Usage: ros2 run read_image img_publisher [img size]"<<std::endl;
        std::cout<< "Ex: ros2 run read_image img_publisher 200kb"<<std::endl;
        return -1;
    }
    std::string size_str = "100kb"; //default
    size_str = argv[1];

    std::string unit = size_str.substr(size_str.length()- 2, 2);
    std::string num_str = size_str.substr(0, size_str.length() -2);
    int index = atoi(num_str.c_str());
    if("mb" == unit){
            index = 1024 * index;
    }
        
    //std::cout<< index << std::endl;

    random_bytes_engine rbe;
    std::vector<unsigned char> data(1024 * index); // 1024 * index
    std::generate(begin(data), end(data), std::ref(rbe));

    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("read_image");
    auto publisher = node->create_publisher<sensor_msgs::msg::Image>("topic", 10);
    rclcpp::WallRate loop_rate(10);
    //cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
    sensor_msgs::msg::Image msg;
    // cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", image).toImageMsg(msg);
    msg.data = data;
    int id_index = 0;

    while(rclcpp::ok()){
//        RCLCPP_INFO(node->get_logger(), "Publishing: "); //'%s'", message.data.c_str());
        msg.header.frame_id = std::to_string(id_index++);
        rclcpp::Time time_now = rclcpp::Clock().now();
        msg.header.stamp = time_now;
        //RCLCPP_INFO(node->get_logger(), "1 ros_TS(Sec): %lu",msg.header.stamp.sec);
        //RCLCPP_INFO(node->get_logger(), "1 ros_TS(NSec): %lu",msg.header.stamp.nanosec);
        RCLCPP_INFO(node->get_logger(), "pub ros_TS(NSec): %lu, frame_id: %s",time_now.nanoseconds(), msg.header.frame_id.c_str());
        publisher->publish(msg);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
