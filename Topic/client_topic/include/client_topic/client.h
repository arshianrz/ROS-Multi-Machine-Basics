#ifndef CLIENT_H
#define CLIENT_H

#include "ros/ros.h"
#include <iostream>
#include <cstdlib>
#include "server_topic/AverageRequest.h"
#include "server_topic/AverageResponse.h"


using namespace std;

class client
{
    private:

    ros::NodeHandle *n;
    ros::Subscriber sub;
    ros::Publisher publisher;
    
    public:

    client();
    void chatterCallBack (const server_topic::AverageResponse::ConstPtr &msg);
    void publishMethod(float val); 

};

#endif //CLIENT_H