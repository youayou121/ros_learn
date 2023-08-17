#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <tf/tf.h>
#include <geometry_msgs/Twist.h>
ros::Publisher pub_vel;
void imu_cb(sensor_msgs::ImuConstPtr imu)
{
    if (imu->orientation_covariance[0] < 0)
    {
        return;
    }
    tf::Quaternion quaternion(
        imu->orientation.x,
        imu->orientation.y,
        imu->orientation.z,
        imu->orientation.w);
    double roll, pitch, yaw;
    tf::Matrix3x3(quaternion).getRPY(roll, pitch, yaw);
    ROS_INFO("翻滚：%.2f,俯仰：%.2f,偏航：%.2f,", roll, pitch, yaw);
    geometry_msgs::Twist cmd_vel;
    double target_yaw = 3.1415926;
    double diff_angle = target_yaw - yaw;
    cmd_vel.angular.z = diff_angle * 0.5;
    pub_vel.publish(cmd_vel);
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "imu_node");
    ros::NodeHandle nh;
    ros::Subscriber imu_sub = nh.subscribe("imu/data", 1, imu_cb);
    pub_vel = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    ros::spin();
    return 0;
}
