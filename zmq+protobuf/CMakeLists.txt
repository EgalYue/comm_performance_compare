cmake_minimum_required(VERSION 3.10)
project(segway_zmq_sample)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ZMQ libzmq)
link_directories(${ZMQ_LIBRARY_DIRS})
include_directories(${ZMQ_INCLUDE_DIRS})

find_package(Protobuf REQUIRED)
if(PROTOBUF_FOUND)
    message(STATUS "protobuf library found")
else()
    message(FATAL_ERROR "protobuf library is needed but cant be found")
endif()

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


# Generate the .h and .cxx files
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ./protocol/raw/image.proto)

# Print path to generated files
message ("PROTO_SRCS = ${PROTO_SRCS}")
message ("PROTO_HDRS = ${PROTO_HDRS}")


include_directories(include)

# include_directories(${PROTO_HDRS})

add_library(pub_lib
        src/Publisher.cpp
        )

add_library(recv_lib
        src/Receiver.cpp
        )


add_executable(segway_zmq_sample src/main.cpp src/Receiver.cpp src/Publisher.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(segway_zmq_sample ${ZMQ_LIBRARIES} ${pub_lib} ${recv_lib} ${PROTOBUF_LIBRARIES} ${OpenCV_LIBS})


add_executable(publisher src/pub_main.cpp src/Publisher.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(publisher ${ZMQ_LIBRARIES} ${pub_lib}  ${PROTOBUF_LIBRARIES} ${OpenCV_LIBS})


add_executable(receiver src/recv_main.cpp src/Receiver.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(receiver ${ZMQ_LIBRARIES} ${recv_lib}  ${PROTOBUF_LIBRARIES} ${OpenCV_LIBS})