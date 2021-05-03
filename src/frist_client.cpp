#include "ros/ros.h"
#include "my_frist_pkg/addTwoint.h"
#include <cstdlib> //for using function atoll

int main(int argc,char **argv)
{
ros::init (argc,argv,"client_node");

if (argc !=3)
{
ROS_INFO("usage: add_two_int_client A B");
return 1; 
}
ros::NodeHandle n;
ros::ServiceClient client = n.serviceClient<my_frist_pkg::addTwoint>("add_two_ints");

my_frist_pkg::addTwoint srv;

srv.request.a = atoll (argv[1]);
srv.request.b = atoll (argv[2]);

if (client.call(srv)){
ROS_INFO(" your sending a = %ld  , b = %ld",(long int)srv.request.a,(long int)srv.request.b);
ROS_INFO("Sum: %ld", (long int)srv.response.sum);}
else {
 ROS_ERROR("Failed to call service add_two_ints");
}
return 0;
}
