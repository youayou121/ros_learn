#include<ros/ros.h>
#include<std_msgs/String.h>
#include<qq_msgs/Carry.h>
void chao_cb(qq_msgs::CarryConstPtr msg)
{
    
    ROS_INFO(msg->data.c_str());
}
void yao_cb(qq_msgs::CarryConstPtr msg)
{
    ROS_WARN(msg->data.c_str());
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"ma_node");
    ros::NodeHandle nh;
    ros::Subscriber sub_chao = nh.subscribe("kaiheiqun",1,chao_cb); 
    ros::Subscriber sub_yao = nh.subscribe("daifeiqun",1,yao_cb); 
    ros::spin();
    return 0;
}
