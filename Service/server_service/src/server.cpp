#include "server_service/server.h"
#include <string>

server::server()
{
    n = new ros::NodeHandle;
    n->param<std::string>("calculate_srv", calculate_srv, "/calculate");

    receiver = n->advertiseService(calculate_srv, &server::adder,this);
    
 
    counter_ = 1;
}

bool server::adder(server_service::feedback::Request &req, server_service::feedback::Response &res)
{
    sum_ += req.ask;
    res.answer = sum_ / counter_;

    ROS_INFO("Request: Number =%f", (float)req.ask);
    ROS_INFO("Sending back Average : [%f]", (float)res.answer);
    counter_++;

    return true;
}
