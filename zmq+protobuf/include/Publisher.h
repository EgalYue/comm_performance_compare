//
// Created by yuehu on 2020/4/14.
//

#ifndef SEGWAY_ROS_SAMPLE_PUBLISHER_H
#define SEGWAY_ROS_SAMPLE_PUBLISHER_H

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include <zmq.h>

class Publisher {

public:
    Publisher();
    ~Publisher();

    void init(const char* endpoint);

    int pubFrame(FrameImage *frame);

private:
    void *m_context;
    void *m_publisher;
    char m_endpoint[100];
    zmq_msg_t m_pub_msg;

};


#endif //SEGWAY_ROS_SAMPLE_PUBLISHER_H
