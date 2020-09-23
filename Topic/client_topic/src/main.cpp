#include "client_topic/client.h"

using namespace ros;

int main(int argc, char **argv)
{
    cout << "Starting Program ..." << endl;

    init(argc, argv, "client_topic");
    
    client sender;
    
    while (ros::ok)
    {
        float num;
        cout << "Enter a Number :";
        cin >> num;
        sender.publishMethod(num);
        spin();
    }
    
    return 0;
}