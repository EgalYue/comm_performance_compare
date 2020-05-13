//
// Created by yuehu on 2020/4/14.
//

#ifndef SEGWAY_ROS_SAMPLE_RECEIVER_H
#define SEGWAY_ROS_SAMPLE_RECEIVER_H

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include <zmq.h>


class Receiver {
public:
    Receiver();
    ~Receiver();

    void init(const char* endpoint);

    void reconnect();

    int recvFrame(FrameImage *frame);
private:

    void *m_context;
    void *m_requester;
    char m_endpoint[100];
    zmq_msg_t m_recv_msg;
    long recv_fail_count;

};


#endif //SEGWAY_ROS_SAMPLE_RECEIVER_H
