//
// Created by yuehu on 2020/4/20.
//

int main(int argc, char *argv[]) {
    std::cout << "=== This is pub ... ===" << std::endl;
    cv::Mat cur_img;
    std::string filepath = "/home/yuehu/Desktop/zmq_test_data/fisheye";
    readImg(filepath, cur_img);

    // convert cv::Mat to FrameImage
    std::shared_ptr<FrameImage> frame_pub = std::make_shared<FrameImage>();
    toFrameImg(cur_img, frame_pub);


    std::string end_point = "tcp://127.0.0.1:8888";
    /*
    // Image descriptor
    Segway_proto::Image img_proto;
    auto header = img_proto.mutable_header();
    header->set_seq(1);
    header->set_frame_id("1");

    auto stamp = header->mutable_stamp();
    stamp->set_sec(1);
    stamp->set_nsec(1);

    img_proto.set_height(480);
    img_proto.set_width(640);
    img_proto.set_encoding("1");
    img_proto.set_is_bigendian(1);
    img_proto.set_step(480 * 3);

    frame_pub->img_desc = img_proto;

    // Image raw data
    int s = 480 * 640 * 3;
    std::vector<uint8_t > raw_data(s);
    generate_vec(raw_data);

    frame_pub->img_data = std::make_shared<std::vector<uint8_t >>(raw_data);
    */

    // publish
    Publisher mq_pub;
    mq_pub.init(end_point.c_str());
    mq_pub.pubFrame(frame_pub.get());
    std::cout<< " --- end ---" << std::endl;

    return 0;
}


#include <fstream>
int main(int argc, char *argv[]) {
    std::cout << "=== This is Recv... ===" << std::endl;
    std::string end_point = argv[1]; // "tcp://127.0.0.1:8888";


    //std::shared_ptr<FrameInfo> frame_recv = std::make_shared<FrameInfo>();

    std::shared_ptr<FrameImage> frame_recv = std::make_shared<FrameImage>();

    Receiver mq_recv;
    mq_recv.init(end_point.c_str());
    int nRecvFailCount = 0;

    std::vector<double > vec;
    int cnt = 500;
    while(cnt >= 0){
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
        std::cout<< ">>> get time from frameImg: "<< frame_recv->img_desc.header().stamp().time_stamp()<<std::endl;
        int64_t curr_ts = std::chrono::duration_cast<std::chrono::nanoseconds>
                (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        std::cout<< ">>> Curr time:" << curr_ts << std::endl;
        printf("Diff time: %10.9f\n",(double)(curr_ts - frame_recv->img_desc.header().stamp().time_stamp()) / 1000000000);

        vec.push_back((double)(curr_ts - frame_recv->img_desc.header().stamp().time_stamp()) / 1000000000);
        cnt--;
//        std::cout<< cnt<<std::endl;
//        cv::imshow("zmq_recv", res);
//        cv::waitKey(1);
    }

    std::ofstream fout;
    fout.open("res.txt",std::ios_base::out);
    if(fout.is_open())
    {
        for(std::vector<double>::iterator i=vec.begin(),end=vec.end(); i!=end; ++i)
        {
            std::cout<< *i << std::endl;
            printf("Diff time: %10.9f\n",*i);
            fout<<std::to_string((*i));
            fout<<"\n";
        }
    }
    fout.close();



    std::cout<< " --- end ---" << std::endl;
    return 0;
}