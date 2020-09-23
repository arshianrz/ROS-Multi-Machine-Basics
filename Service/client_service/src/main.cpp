#include "client_service/client.h"

int main(int argc,char **argv)
{
    ros::init(argc,argv,"client_service");

    client send;
    while(ros::ok())
    {
        send.send();

        ros::spin();

    }


    return 0;
}
