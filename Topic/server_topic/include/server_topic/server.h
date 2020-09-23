#ifndef SERVER_H
#define SERVER_H

#include "ros/ros.h"
#include <iostream>
#include <sstream>
#include <std_msgs/Float32.h>
#include <server_topic/AverageRequest.h>
#include <server_topic/AverageResponse.h>

using namespace std;

class server
{
private:
    ros::NodeHandle *n;
    ros::Subscriber sub;
    ros::Publisher publisher;
    float Sum_;
    int counter_;
    float avg;

public:
    server();
    void chatterCallBack (const server_topic::AverageRequest::ConstPtr &msg);
    void setCounter(int val);
    int getCounter();
    void setSum(float val);
    float getSum();

};


#endif //CLIENT_H