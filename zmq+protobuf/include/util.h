//
// Created by yuehu on 2020/4/15.
//

#ifndef SEGWAY_ZMQ_SAMPLE_UTIL_H
#define SEGWAY_ZMQ_SAMPLE_UTIL_H

#include "image.pb.h"


class FrameInfo{
    /*
     * Just for test, unused now!
     */
public:
    uint32_t *id;
};



class FrameImage{
public:
    Segway_proto::Image img_desc; // image descriptor
    std::shared_ptr<std::vector<uint8_t>> img_data; // image raw data
};





#endif //SEGWAY_ROS_SAMPLE_UTIL_H

