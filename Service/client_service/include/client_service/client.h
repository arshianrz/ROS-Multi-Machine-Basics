#ifndef CLIENT_H
#define CLIENT_H

#include "ros/ros.h"
#include <cstdlib>
#include "server_service/feedback.h"
#include <iostream>

using namespace std;

class client
{
private:
    ros::NodeHandle *n;
    ros::ServiceClient sender;


public:
    client();
    int send();

};


#endif // CLIENT_H
