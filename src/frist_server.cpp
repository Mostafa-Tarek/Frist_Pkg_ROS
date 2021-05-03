#include "ros/ros.h"
#include "my_frist_pkg/addTwoint.h"
bool add(my_frist_pkg::addTwoint::Request &req,
         my_frist_pkg::addTwoint::Response &res)
{
res.sum=req.a+req.b;
ROS_INFO("request : x=%ld , y=%ld",(long int)req.a,(long int)req.b);
ROS_INFO("sending response : %ld",(long int)res.sum);
return true;
}

int main(int argc,char**argv)
{
ros::init (argc,argv,"server_node");
ros::NodeHandle n;

ros::ServiceServer service = n.advertiseService("add_two_ints", add);
ROS_INFO("Ready to add two ints");
ros::spin();
return 0;
}
