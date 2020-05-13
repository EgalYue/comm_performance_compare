
cmake_minimum_required(VERSION 2.8.12)

project("generated_code")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


message(STATUS "Configuring ImgMsg...")
add_library(ImgMsg_lib ImgMsg.cxx)
target_link_libraries(ImgMsg_lib fastcdr fastrtps)

add_executable(ImgMsg ImgMsgPubSubTypes.cxx ImgMsgPublisher.cxx ImgMsgSubscriber.cxx ImgMsgPubSubMain.cxx)
target_link_libraries(ImgMsg fastcdr fastrtps
        ImgMsg_lib ${OpenCV_LIBS})



