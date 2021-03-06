cmake_minimum_required(VERSION 3.5)
project(read_image)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)


add_executable(img_publisher src/img_publisher.cpp)
ament_target_dependencies(img_publisher
        "rclcpp"
        "std_msgs"
        "sensor_msgs"
        "std_msgs"
        "rclcpp_components"
        "OpenCV")
install(TARGETS
        img_publisher
        DESTINATION lib/${PROJECT_NAME}
        )


add_executable(img_subscriber src/img_subscriber.cpp)
ament_target_dependencies(img_subscriber
        "rclcpp"
        "std_msgs"
        "sensor_msgs"
        "std_msgs"
        "rclcpp_components"
        "OpenCV")

install(TARGETS
        img_subscriber
        DESTINATION lib/${PROJECT_NAME}
        )
ament_package()
