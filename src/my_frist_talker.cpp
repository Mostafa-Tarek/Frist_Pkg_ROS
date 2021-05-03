#include "ros/ros.h"
#include "my_frist_pkg/MSTutorial.h"
int main (int argc,char**argv)
{
   ros::init(argc,argv,"talker_topic");
   ros::NodeHandle n;

  ros::Publisher my_frist_pub =n.advertise<my_frist_pkg::MSTutorial>("topic_msg",100);

ros::Rate loop_rate(10);

my_frist_pkg::MSTutorial msg;

int count = 0;

while (ros::ok())
{
msg.stamp =ros::Time::now();
msg.data=count;
ROS_INFO ("send msg= %d",msg.stamp.sec);
ROS_INFO ("send msg= %d",msg.stamp.nsec);
ROS_INFO ("send msg= %d",msg.data);
my_frist_pub.publish(msg);
loop_rate.sleep();
++count;
}
return 0;
}
