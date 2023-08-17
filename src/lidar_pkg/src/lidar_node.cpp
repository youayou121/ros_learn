#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
ros::Publisher vel_pub;
void lidar_cb(sensor_msgs::LaserScanConstPtr scan)
{
    int mid = scan->ranges.size() / 2;
    double dist = scan->ranges[mid];
    geometry_msgs::Twist cmd_vel;
    ROS_INFO("机器人正前方障碍物距离: ranges[%d]=%.2f", mid, dist);
    if (dist < 1.5)
    {
        cmd_vel.linear.x = 0;
        cmd_vel.angular.z = 1;
    }
    else
    {
        cmd_vel.linear.x = 0.5;
        cmd_vel.angular.z = 0;
    }
    vel_pub.publish(cmd_vel);
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "lidar_node");
    ros::NodeHandle nh;
    ros::Subscriber sub_scan = nh.subscribe("scan", 10, &lidar_cb);
    vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    ros::spin();
    return 0;
}
