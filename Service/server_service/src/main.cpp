#include "server_service/server.h"
#include <iostream>

int main(int argc , char **argv)
{
    ros::init(argc,argv,"server_service");

    server receiver;

    ros::spin();

    return 0;
}