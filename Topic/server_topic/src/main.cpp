#include "ros/ros.h"
#include "server_topic/server.h"

using namespace ros;

int main(int argc, char **argv)
{
    init(argc, argv, "server_topic");
    
    cout << "Data calculating ..." << endl;
    
    server receive;

    spin();
    
    return 0;
}
