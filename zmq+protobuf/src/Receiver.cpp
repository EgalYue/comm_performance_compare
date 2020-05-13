//
// Created by yuehu on 2020/4/14.
//

#include "Receiver.h"
#include <assert.h>
#include <cstring>


Receiver::Receiver() {

}

void Receiver::init(const char* endpoint){
    if(m_endpoint != endpoint){
        strcpy(m_endpoint, endpoint);
    }

    m_context = zmq_ctx_new();
    m_requester = zmq_socket(m_context, ZMQ_SUB);

    int hwm = 5;
    zmq_setsockopt(m_requester, ZMQ_RCVHWM, &hwm, sizeof(int));
    int recvbuf = 20 * 1048576;
    zmq_setsockopt(m_requester, ZMQ_RCVBUF, &recvbuf, sizeof(int));
    zmq_setsockopt(m_requester, ZMQ_SUBSCRIBE, "", 0);//TODO filter

    if (zmq_connect(m_requester, m_endpoint) < 0){
        return;
    }
    zmq_msg_init(&m_recv_msg);
    recv_fail_count = 0;
}

Receiver::~Receiver() {
    zmq_msg_close(&m_recv_msg);
    zmq_close(m_requester);
    zmq_ctx_destroy(m_context);
}

void Receiver::reconnect() {
    zmq_msg_close(&m_recv_msg);
    zmq_close(m_requester);
    zmq_ctx_destroy(m_context);

    init(m_endpoint);
}

int Receiver::recvFrame(FrameImage *frame) {
    int recv_to = 50;
    zmq_setsockopt(m_requester, ZMQ_RCVTIMEO, &recv_to, sizeof(int));
    if(recv_fail_count > 5000 / recv_to){
        std::cout<< __LINE__ << "Reconnect to "<< m_endpoint << std::endl;
    }

    int more;
    size_t more_size = sizeof(more);

    {
        int rc = zmq_msg_init(&m_recv_msg);
        assert(rc ==0);

        rc = zmq_msg_recv(&m_recv_msg, m_requester, 0);
        if(rc == -1){
            recv_fail_count++;
            return 0;
        }
        recv_fail_count = 0;

        int img_protolen = zmq_msg_size(&m_recv_msg);

        std::shared_ptr<std::vector<uint8_t>> vec = std::make_shared<std::vector<uint8_t> >();
        vec->resize(img_protolen);
        memcpy(vec->data(), zmq_msg_data(&m_recv_msg), img_protolen);
        frame->img_desc.ParseFromArray(zmq_msg_data(&m_recv_msg), img_protolen);
        std::cout<< ">>> frame id: "<< frame->img_desc.header().frame_id() <<std::endl;

        zmq_msg_close(&m_recv_msg);
    }

    zmq_getsockopt(m_requester, ZMQ_RCVMORE, &more, &more_size);
    if (!more) {
        return 0;
    }

    {
        zmq_msg_t m_recv_msg;
        int rc = zmq_msg_init(&m_recv_msg);
        assert(rc ==0);

        rc = zmq_msg_recv(&m_recv_msg, m_requester, 0);
        int raw_datalen = zmq_msg_size(&m_recv_msg);
        std::shared_ptr<std::vector<uint8_t >> vec = std::make_shared<std::vector<uint8_t> >();
        vec->resize(raw_datalen);
        memcpy(vec->data(), zmq_msg_data(&m_recv_msg), raw_datalen);
        frame->img_data = vec;

        zmq_msg_close(&m_recv_msg);
    }

    while (true) {
        zmq_getsockopt(m_requester, ZMQ_RCVMORE, &more, &more_size);
        if (!more) {
            break;
        }
        //TODO
    }

    return 1;
}