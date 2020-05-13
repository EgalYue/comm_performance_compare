// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file ImgMsgPublisher.cpp
 * This file contains the implementation of the publisher functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/attributes/PublisherAttributes.h>

#include <fastrtps/Domain.h>
#include <fastrtps/transport/TCPv4TransportDescriptor.h>

#include <thread>
#include <chrono>

#include "ImgMsgPublisher.h"
#include <opencv2/opencv.hpp>
#include <unistd.h> //sleep
#include <algorithm>
#include <random>
#include <functional>
#include <climits>

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;


using random_bytes_engine = std::independent_bits_engine<std::default_random_engine, CHAR_BIT, unsigned char>;

ImgMsgPublisher::ImgMsgPublisher() : mp_participant(nullptr), mp_publisher(nullptr) {}

ImgMsgPublisher::~ImgMsgPublisher() {	Domain::removeParticipant(mp_participant);}

bool ImgMsgPublisher::init(        const std::string &wan_ip,
                                   unsigned short port,
                                   bool use_tls,
                                   const std::vector<std::string>& whitelist)
{
    // Create RTPSParticipant
    ParticipantAttributes PParam;
    PParam.rtps.builtin.discovery_config.discoveryProtocol = DiscoveryProtocol_t::SIMPLE;
    PParam.rtps.builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
    PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
    PParam.rtps.builtin.discovery_config.leaseDuration = c_TimeInfinite;
    PParam.rtps.setName("Participant_publisher");  //You can put here the name you want

    PParam.rtps.useBuiltinTransports = false;

    std::shared_ptr<TCPv4TransportDescriptor> descriptor = std::make_shared<TCPv4TransportDescriptor>();

    for (std::string ip : whitelist)
    {
        descriptor->interfaceWhiteList.push_back(ip);
        std::cout << "Whitelisted " << ip << std::endl;
    }

    if (use_tls)
    {
        using TLSOptions = TCPTransportDescriptor::TLSConfig::TLSOptions;
        descriptor->apply_security = true;
        descriptor->tls_config.password = "test";
        descriptor->tls_config.cert_chain_file = "server.pem";
        descriptor->tls_config.private_key_file = "server.pem";
        descriptor->tls_config.tmp_dh_file = "dh2048.pem";
        descriptor->tls_config.add_option(TLSOptions::DEFAULT_WORKAROUNDS);
        descriptor->tls_config.add_option(TLSOptions::SINGLE_DH_USE);
        descriptor->tls_config.add_option(TLSOptions::NO_SSLV2);
    }

    descriptor->wait_for_tcp_negotiation = false;
    descriptor->sendBufferSize = 3211264;
    descriptor->receiveBufferSize = 3211264;

    if (!wan_ip.empty())
    {
        descriptor->set_WAN_address(wan_ip);
        std::cout << wan_ip << ":" << port << std::endl;
    }
    descriptor->add_listener_port(port);
    PParam.rtps.userTransports.push_back(descriptor);


    mp_participant = Domain::createParticipant(PParam);
    if(mp_participant == nullptr)
    {
        return false;
    }

    //Register the type

    Domain::registerType(mp_participant, static_cast<TopicDataType*>(&myType));

    // Create Publisher

    PublisherAttributes Wparam;
    Wparam.qos.m_publishMode.kind = ASYNCHRONOUS_PUBLISH_MODE;
    Wparam.topic.topicKind = NO_KEY;
    Wparam.topic.topicDataType = myType.getName();  //This type MUST be registered
    Wparam.topic.topicName = "ImgMsgPubSubTopic";

    Wparam.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
//    Wparam.topic.historyQos.depth = 30;
//    Wparam.topic.resourceLimitsQos.max_samples = 50;
//    Wparam.topic.resourceLimitsQos.allocated_samples = 20;
    Wparam.times.heartbeatPeriod.seconds = 0;
    //Wparam.times.heartbeatPeriod.nanosec = 200 * 1000 * 1000;
    Wparam.times.heartbeatPeriod.fraction(4294967 * 500); //500 ms

    Wparam.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;


    mp_publisher = Domain::createPublisher(mp_participant,Wparam,static_cast<PublisherListener*>(&m_listener));

    if(mp_publisher == nullptr)
    {
        return false;
    }

    std::cout << "Publisher created, waiting for Subscribers." << std::endl;
    return true;
}

void ImgMsgPublisher::PubListener::onPublicationMatched(Publisher* pub,MatchingInfo& info)
{
    (void)pub;

    if (info.status == MATCHED_MATCHING)
    {
        n_matched++;
        std::cout << "Publisher matched" << std::endl;
    }
    else
    {
        n_matched--;
        std::cout << "Publisher unmatched" << std::endl;
    }
}

void ImgMsgPublisher::runThread(uint32_t samples, uint32_t sleep, std::string datasize)
{
    if (samples == 0)
    {
        while (!stop)
        {
            if (publish(false))
            {
//                std::cout << "Message: " << m_imgMsg.message() << " with index: " << m_Hello.index() << " SENT" <<
//                          std::endl;
                std::cout << "Message: " << " with index: " << " SENT" << std::endl;
            }
            //std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
        }
    }
    else
    {   
        m_imgMsg.header().seq(1);
        m_imgMsg.height(640); // useless
        m_imgMsg.width(480); //uesless
        m_imgMsg.encoding("mono8"); //TODO
        m_imgMsg.is_bigendian(1); //TODO
        m_imgMsg.step(640*480); //useless
        random_bytes_engine rbe;
        std::string unit = datasize.substr(datasize.length()- 2, 2);
        std::string num_str = datasize.substr(0, datasize.length() -2);
        int index = atoi(num_str.c_str());
        if("mb" == unit){
            index = 1024 * index;
        }
        std::cout<< "img size: "<< datasize <<std::endl;
        std::vector<unsigned char> data(1024 * index); // 1024 * index
        std::generate(begin(data), end(data), std::ref(rbe));
        m_imgMsg.data(data);
        
        int frame_id = 0;
        while(true)
        {
            usleep(100000);

            int64_t curr_ts = std::chrono::duration_cast<std::chrono::nanoseconds>
                              (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
            std::cout<< "Send time: "<< curr_ts << " frame_id: "<< frame_id << std::endl;
            m_imgMsg.header().stamp().time_stamp(curr_ts);
            m_imgMsg.header().frame_id(std::to_string(frame_id));

            //std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
            frame_id++;
            publish();
        }
    }
}

void ImgMsgPublisher::run(uint32_t samples, uint32_t sleep, std::string datasize)
{
    stop = false;
    std::thread thread(&ImgMsgPublisher::runThread, this, samples, sleep, datasize);
    if (samples == 0)
    {
        std::cout << "Publisher running. Please press enter to stop the Publisher at any time." << std::endl;
        std::cin.ignore();
        stop = true;
    }
    else
    {
        std::cout << "Publisher running " << samples << " samples." << std::endl;
    }
    thread.join();
}

bool ImgMsgPublisher::publish(bool waitForListener)
{
    if (!waitForListener || m_listener.n_matched > 0)
    {
        mp_publisher->write((void*)&m_imgMsg);
        std::cout<<" >>> data size: " << m_imgMsg.data().size()<< std::endl;
        return true;
    }
    return false;
}


