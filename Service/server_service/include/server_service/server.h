#ifndef SERVER_H
#define SERVER_H

#include "ros/ros.h"
#include <cstdlib>
#include "server_service/feedback.h"
#include <string>
#include <iostream>


using namespace ros;

class server
{
private:

    ros::NodeHandle *n;
    ros::ServiceServer receiver;
    int counter_;
    float sum_;
    std::string calculate_srv;

public:
    server();
    bool adder(server_service::feedback::Request &req,server_service::feedback::Response &res);
    
};

#endif //SERVER_H