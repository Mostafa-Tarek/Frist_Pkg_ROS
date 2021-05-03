#include "ros/ros.h"
#include "my_frist_pkg/area_of_Rect.h"
bool area_RECT(my_frist_pkg::area_of_Rect::Request &req,
my_frist_pkg::area_of_Rect::Response &res) {
res.area=req.length*req.width;
ROS_INFO("send req : len=%ld cm ,w=%ld cm",(long int)req.length,(long int)req.width);
ROS_INFO("sending back response : area=%ld cm",(long int)res.area);
return true;
}
int main(int argc ,char **argv){

ros::init (argc,argv,"server_Rect");
ros::NodeHandle n;
ros::ServiceServer server=n.advertiseService("Area_of_RECT",area_RECT);
ROS_INFO("USE the Service");
ros::spin();
return 0; 
}
