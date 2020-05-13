//
// Created by yuehu on 2020/4/14.
//

#include "Publisher.h"
#include <assert.h>
#include <cstring>

Publisher::Publisher()  {

}

void Publisher::init(const char* endpoint){
    if(m_endpoint != endpoint){
        strcpy(m_endpoint, endpoint);
    }

    m_context = zmq_ctx_new();
    m_publisher = zmq_socket(m_context, ZMQ_PUB);
    uint64_t hwm = 5;
    zmq_setsockopt (m_publisher, ZMQ_SNDHWM, &hwm, sizeof (hwm));

    if (zmq_bind(m_publisher, m_endpoint) < 0){
        return;
    }
    std::cout<< "Publisher start: "<< std::endl;
}

Publisher::~Publisher() {
    zmq_msg_close(&m_pub_msg);
    zmq_close(m_publisher);
    zmq_ctx_destroy(m_context);
}

int Publisher::pubFrame(FrameImage *frame){
    // 1. publisher image descriptor
    auto img_proto = frame->img_desc;
    size_t img_proto_size = img_proto.ByteSizeLong();
    std::cout<< "img_proto_size: "<< img_proto_size << std::endl;

    std::shared_ptr<std::vector<uint8_t >> buffer = std::make_shared<std::vector<uint8_t>>();
    buffer->resize(img_proto_size);
    img_proto.SerializeToArray(buffer->data(), img_proto_size);

    zmq_msg_init_size(&m_pub_msg, img_proto_size);

    memcpy(zmq_msg_data(&m_pub_msg), buffer->data(), img_proto_size);
    int rc = zmq_msg_send(&m_pub_msg, m_publisher, ZMQ_SNDMORE);
    assert(rc == img_proto_size);

    zmq_msg_close(&m_pub_msg);

    // 2. publisher image raw data
    auto img_raw_data = frame->img_data;
    size_t raw_data_size = img_raw_data->size();
    std::cout<< "img_raw_data size: " << raw_data_size << std::endl;
    zmq_msg_init_size(&m_pub_msg, raw_data_size);

    memcpy(zmq_msg_data(&m_pub_msg), img_raw_data->data(), raw_data_size);
    int rc2 = zmq_msg_send(&m_pub_msg, m_publisher, 0);
    assert(rc2 == raw_data_size);

    zmq_msg_close(&m_pub_msg);

    return 1;
}