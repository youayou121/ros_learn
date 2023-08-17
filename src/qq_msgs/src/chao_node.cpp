#include<ros/ros.h>
#include<qq_msgs/Carry.h>
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"chao_node");
    ros::NodeHandle nh;
    ros::Publisher chao_pub = nh.advertise<qq_msgs::Carry>("/kaiheiqun",1);
    qq_msgs::Carry msg;
    msg.grade = "王者";
    msg.star = 50;
    msg.data = "我带飞";
    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        chao_pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}