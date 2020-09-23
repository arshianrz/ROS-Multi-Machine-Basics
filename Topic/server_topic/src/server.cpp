#include "server_topic/server.h"

using namespace std;

server::server()
{
    n = new ros::NodeHandle;
    sub = n->subscribe("calculate", 1, &server::chatterCallBack, this);
    publisher = n->advertise<server_topic::AverageResponse>("result", 1);
    counter_=0;
}

void server::setCounter(int val)
{
    counter_=val;
}

int server::getCounter()
{
    return counter_;
}
void server::setSum(float val)
{
    Sum_= val;
}
float server::getSum()
{
    return Sum_;
}

void server::chatterCallBack(const server_topic::AverageRequest::ConstPtr &msg)
{
    
    float a = msg->A;
    cout<<"(Data received from client is : "<< a <<" )"<<endl;
    Sum_+= a;
    counter_++;
    avg = Sum_/counter_;
    cout<<"Sum is :"<< getSum() <<endl;
    cout<<"Average on Server is :"<< avg <<endl ;
    
    cout<<endl;

    server_topic::AverageResponse resp;
    resp.Average = avg;
    publisher.publish(resp);
}
