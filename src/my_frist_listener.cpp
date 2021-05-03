#include "ros/ros.h"
#include "my_frist_pkg/MSTutorial.h"
void msgCallback(const my_frist_pkg::MSTutorial::ConstPtr&msg)
{
ROS_INFO ("recieve msg= %d",msg->stamp.sec);
ROS_INFO ("recieve msg= %d",msg->stamp.nsec);
ROS_INFO ("recieve msg= %d",msg->data);
}
int main(int argc , char* argv[]) 
{
ros :: init (argc , argv ,"listener_topic");
ros::NodeHandle n;
ros::Subscriber my_frist_sub =n.subscribe("topic_msg",1000,msgCallback);
ros::spin();
return 0;
}
