#include <iostream>
#include <zmq.h>

#include <cstring>
#include <memory>

#include "Publisher.h"
#include "Receiver.h"
#include "util.h"

#include "image.pb.h"


int main(int argc, char *argv[]) {
    std::cout << "=== MAIN ===" << std::endl;

    std::string end_point = "tcp://127.0.0.1:8888";


//    const char *src = "123";
//    std::cout<< strlen(src)<<std::endl;
//    char* dest = (char*)malloc(strlen(src)+1);
//    std::cout<< strlen(dest)<<std::endl;
//    memcpy(dest, src, strlen(src)+1);
//
//    printf("Receiving data: %s\n", dest);



//    if (argc > 1){
//        // publisher
//        std::cout<< ">>> This is Pub"<< std::endl;
//        std::shared_ptr<FrameInfo> frame_pub = std::make_shared<FrameInfo>();
//        std::string hello_str= "Hello World!";
//        frame_pub->helloWorld = strcpy(new char[hello_str.length() + 1], hello_str.c_str());
//
//        Publisher mq_pub;
//        mq_pub.init(end_point.c_str());
//        mq_pub.pubFrame(frame_pub.get());
//    } else{
//        // receiver
//        std::cout<< ">>> This is Recv"<< std::endl;
//        std::shared_ptr<FrameInfo> frame_recv = std::make_shared<FrameInfo>();
//
//        Receiver mq_recv;
//        mq_recv.init(end_point.c_str());
//        mq_recv.recvFrame(frame_recv.get());
//    }


    std::cout<< " --- end ---" << std::endl;
    return 0;
}