#include <ros/ros.h>
#include <srv_pkg/AddInts.h>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    if (argc != 3)
    {
        ROS_ERROR("提交的参数个数不对！");
        return 0;
    }
    ros::init(argc, argv, "client_node");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<srv_pkg::AddInts>("add_ints");
    srv_pkg::AddInts ints;
    ints.request.num1 = atoi(argv[1]);
    ints.request.num2 = atoi(argv[2]);
    // ints.request.num1 = 100;
    // ints.request.num2 = 200;
    // client.waitForExistence();
    ros::service::waitForService("add_ints");
    bool flag = client.call(ints);
    if (flag)
    {
        ROS_INFO("调用服务成功：num1 + num2 = %d + %d = %d", ints.request.num1, ints.request.num2, ints.response.sum);
    }
    else
    {
        ROS_INFO("调用服务失败！");
    }
    return 0;
}
