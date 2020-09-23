#include "client_topic/client.h"

using namespace std;
using namespace ros;

client::client()
{
    n = new NodeHandle;
    publisher = n->advertise<server_topic::AverageRequest>("calculate", 1);
    sub = n->subscribe("result", 1, &client::chatterCallBack, this);
    //line below was spin();
    spinOnce();   
}

void client::publishMethod(float a)
{        
    server_topic::AverageRequest req;
    req.A = a;
    publisher.publish(req);
    spin();
}
   

void client::chatterCallBack(const server_topic::AverageResponse::ConstPtr &msg)
{
    cout <<"Average is :" << msg->Average << endl;
    publisher = n->advertise<server_topic::AverageRequest>("calculate", 1);
 
    if(msg->Average < 0)
    {
        ROS_WARN("Average is Minus.");
    }

      while (ros::ok)
    {
        float num;
        cout << "Enter a Number :";
        cin >> num;
        this->publishMethod(num);
        spin();
    }
    cout<<endl;
    spin();
}