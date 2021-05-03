#include "ros/ros.h"
#include "my_frist_pkg/area_of_Rect.h"
#include <cstdlib>
int main(int argc ,char **argv){

ros::init (argc,argv,"client_Rect");
ros::NodeHandle n;
ros::ServiceClient client=n.serviceClient<my_frist_pkg::area_of_Rect>("Area_of_RECT");
if (argc !=3){
ROS_INFO("you can use the service enter len and w");
return 1;
}

my_frist_pkg::area_of_Rect srv;
srv.request.length=atoll (argv[1]);
srv.request.width= atoll (argv[2]);
if (client.call(srv)){
ROS_INFO("lenght = %ld,width = %ld",(long int)srv.request.length,(long int)srv.request.width);
ROS_INFO("response of the service : %ld",(long int)srv.response.area);
}
else {
ROS_ERROR("Failed to call the service");
return 1;
}
return 0;
}
