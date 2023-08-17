#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <action_pkg/AddIntsAction.h>
typedef actionlib::SimpleActionServer<action_pkg::AddIntsAction> Server;
void addCB(const action_pkg::AddIntsGoalConstPtr goalPtr, Server *sas)
{
    int start_num = goalPtr->num1;
    int end_num = goalPtr->num2;
    ROS_INFO("收到数据:start_num:%d,end_num:%d", start_num, end_num);
    ros::Rate rate(2);
    int result = 0;
    ROS_INFO("正在进行反馈");
    for (int i = start_num; i <= end_num; i++)
    {
        result += i;
        action_pkg::AddIntsFeedback feedback;
        feedback.progress_bar = (double)(i - start_num) / (double)(end_num - start_num);
        sas->publishFeedback(feedback);
        ROS_INFO("progress_bar:%f", feedback.progress_bar);
        rate.sleep();
    }
    action_pkg::AddIntsResult rs;
    rs.result = result;
    ROS_INFO("计算结束：result = %d", result);
    sas->setSucceeded(rs);
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "server_node");
    ros::NodeHandle nh;
    Server sas(nh, "add_ints", boost::bind(&addCB, _1, &sas), false);
    sas.start();
    ros::spin();
    return 0;
}
