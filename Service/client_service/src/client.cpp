#include "client_service/client.h"

using namespace std;

client::client()
{
    n = new ros::NodeHandle;

    sender = n -> serviceClient<server_service::feedback>("calculate_srv");

}

int client::send()
{
    float num;
    server_service::feedback number;
    for (;ros::ok();)
    {
        cout<<"Enter a number :";
        cin>>num;
        number.request.ask = num;
       // num = atoll(argv[1]);


        if (sender.call(number))
        {
          ROS_INFO("average: %f", (float)number.response.answer);
        }
        else
        {
          ROS_ERROR("Failed to call service feedback");
          return 1;
        }
    }
}
