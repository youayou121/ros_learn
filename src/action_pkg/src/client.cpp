#include <ros/ros.h>
#include <action_pkg/AddIntsAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<action_pkg::AddIntsAction> Client;
void doneCb(const actionlib::SimpleClientGoalState &state, const action_pkg::AddIntsResultConstPtr &result)
{
    if(state.state_ == state.SUCCEEDED)
    {
        ROS_INFO("响应成功！最终结果为%d",result->result);
    }
    else
    {
        ROS_ERROR("请求失败！");
    }
}
void activeCb()
{
    ROS_INFO("连接建立");
}
void feedbackCb(const action_pkg::AddIntsFeedbackConstPtr &feedback)
{
    ROS_INFO("当前进度：%.2f",feedback->progress_bar);
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "client_node");
    ros::NodeHandle nh;
    Client sac(nh, "add_ints");
    action_pkg::AddIntsGoal goal;
    goal.num1 = 0;
    goal.num2 = 10;
    ROS_INFO("客户端已启动，正在等待服务端启动...");
    sac.waitForServer();
    sac.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);
    ros::spin();
    return 0;
}
