#include<ros/ros.h>
#include<std_msgs/String.h>
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"yao_node");
    ros::NodeHandle nh;
    ros::Publisher chao_pub = nh.advertise<std_msgs::String>("/daifeiqun",1);
    std_msgs::String msg;
    msg.data = "求上车";
    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        chao_pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}