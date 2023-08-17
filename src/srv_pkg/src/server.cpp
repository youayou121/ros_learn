#include <ros/ros.h>
#include <srv_pkg/AddInts.h>
bool Add(srv_pkg::AddInts::Request &request,
         srv_pkg::AddInts::Response &response)
{
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到的数据为：num1 = %d,num2 = %d。",num1,num2);
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和的结果为：sum = %d 。",sum);
    return true;
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "server_node");
    ros::NodeHandle nh;
    ros::ServiceServer srv = nh.advertiseService("add_ints", Add);
    ros::spin();
    return 0;
}
