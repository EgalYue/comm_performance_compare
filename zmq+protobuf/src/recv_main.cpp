//
// Created by yuehu on 2020/4/16.
//

#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>

#include "Publisher.h"
#include "Receiver.h"

#include "image.pb.h"


cv::Mat matFromFrameImg(std::shared_ptr<FrameImage> src);

int main(int argc, char *argv[]) {
    std::cout << "=== This is Recv... ===" << std::endl;
    std::string end_point = argv[1]; // "tcp://127.0.0.1:8888";


    //std::shared_ptr<FrameInfo> frame_recv = std::make_shared<FrameInfo>();

    std::shared_ptr<FrameImage> frame_recv = std::make_shared<FrameImage>();

    Receiver mq_recv;
    mq_recv.init(end_point.c_str());
    int nRecvFailCount = 0;
    while(1){
        if (!mq_recv.recvFrame(frame_recv.get())) {
            std::cout << "Recv Frame Timeout" << std::endl;
            {
                nRecvFailCount++;

                if (nRecvFailCount > 20) {
                    mq_recv.reconnect();
                    nRecvFailCount = 0;
                }
            }
            continue;
        }

        cv::Mat res = matFromFrameImg(frame_recv);
        std::cout<< "data size: "<< frame_recv->img_data->size()<<std::endl;
        std::cout<< "Pub time: "<< frame_recv->img_desc.header().stamp().time_stamp()<<std::endl;
        int64_t curr_ts = std::chrono::duration_cast<std::chrono::nanoseconds>
                (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        std::cout<< "Sub time: " << curr_ts << std::endl;
        printf("Diff time: %10.9f\n",(double)(curr_ts - frame_recv->img_desc.header().stamp().time_stamp()) / 1000000000);
    }

    std::cout<< " --- end ---" << std::endl;
    return 0;
}

cv::Mat matFromFrameImg(std::shared_ptr<FrameImage> src){
    uint32_t src_height = src->img_desc.height();
    uint32_t src_width = src->img_desc.width();
    int source_type = CV_8UC1; //TODO
    uint32_t src_step = src->img_desc.step();
    cv::Mat dst(src_height, src_width, CV_8UC1, src->img_data->data(), src_step);
    return dst;
}