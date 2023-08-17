#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"vel_node");
    ros::NodeHandle nh;
    ros::Publisher pub_vel = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    geometry_msgs::Twist cmd_vel;
    cmd_vel.linear.x = 0.5;
    cmd_vel.angular.z = 1.0;
    ros::Rate rate(10);
    while (ros::ok())
    {
        pub_vel.publish(cmd_vel);
    }
    
    return 0;
}
