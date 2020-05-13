//
// Created by yuehu on 2020/4/16.
//

#include <iostream>
#include <memory>
#include <algorithm>
#include <random>
#include <functional>
#include <climits>
#include <vector>

#include <zmq.h>
#include <opencv2/opencv.hpp>
#include <unistd.h> //sleep

#include "Publisher.h"
#include "image.pb.h"

#include <algorithm>
#include <random>
#include <functional>
#include <climits>
using random_bytes_engine = std::independent_bits_engine<std::default_random_engine, CHAR_BIT, unsigned char>;

void generate_vec(std::vector<uint8_t> &data);

void toFrameImg(const std::vector<unsigned char>& src, std::shared_ptr<FrameImage> dst);


int main(int argc, char *argv[]) {
    if(argc < 3){
        std::cout<< "Usage: publisher [ip:port] [img size]"<<std::endl;
        std::cout<< "Ex: publisher tcp://127.0.0.1:8888 200kb"<<std::endl;
        return -1;
    }

    std::string size_str = "100kb"; //default
    size_str = argv[2];

    std::string unit = size_str.substr(size_str.length()- 2, 2);
    std::string num_str = size_str.substr(0, size_str.length() -2);
    int index = atoi(num_str.c_str());
    if("mb" == unit){
            index = 1024 * index;
    }

    random_bytes_engine rbe;
    std::vector<unsigned char> data(1024 * index); // 1024 * index
    std::generate(begin(data), end(data), std::ref(rbe));


    std::cout << "=== This is pub ... ===" << std::endl;
    std::string end_point = argv[1]; // "tcp://127.0.0.1:8888";
    Publisher mq_pub;
    mq_pub.init(end_point.c_str());

    std::shared_ptr<FrameImage> frame_pub = std::make_shared<FrameImage>();

    toFrameImg(data, frame_pub);
    int frame_id =0;
    while(true){
        usleep(100000);    
        int64_t curr_ts = std::chrono::duration_cast<std::chrono::nanoseconds>
                          (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        std::cout<< "Send time: " << curr_ts << " frame_id: "<< frame_id << std::endl;
        frame_pub->img_desc.mutable_header()->set_frame_id(std::to_string(frame_id));
        frame_pub->img_desc.mutable_header()->mutable_stamp()->set_time_stamp(curr_ts);

        // publish
        mq_pub.pubFrame(frame_pub.get());
        frame_id++;
    }

    std::cout<< " --- end ---" << std::endl;
    return 0;
}


void generate_vec(std::vector<uint8_t> &data){
    using random_bytes_engine = std::independent_bits_engine<std::default_random_engine, CHAR_BIT, uint8_t>;
    random_bytes_engine rbe;
    std::generate(begin(data), end(data), std::ref(rbe));
}

void toFrameImg(const std::vector<unsigned char>& src, std::shared_ptr<FrameImage> dst){
    // img descriptor
    Segway_proto::Image img_proto;
    auto header = img_proto.mutable_header();
    header->set_seq(1); //TODO
    header->set_frame_id("0"); // TODO

    auto stamp = header->mutable_stamp(); //TODO
    stamp->set_time_stamp(0);

    img_proto.set_height(640); //useless
    img_proto.set_width(480); //uesless
    img_proto.set_encoding("mono8"); //TODO
    img_proto.set_is_bigendian(1); //TODO
    img_proto.set_step(640*480); //useless

    dst->img_desc = img_proto;
    // img raw data
    dst->img_data = std::make_shared<std::vector<uint8_t >>(src);
}