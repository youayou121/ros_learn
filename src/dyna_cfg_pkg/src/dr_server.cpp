#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <dyna_cfg_pkg/drConfig.h>

void drCb(dyna_cfg_pkg::drConfig &config, uint32_t level)

{
    ROS_INFO("\n int_param被改为：%d \n double_param被改为：%f \n str_param被改为：%s \n bool_param被改为：%d \n list_param被改为：%d \n",
             config.int_param,
             config.double_param,
             config.str_param.c_str(),
             config.bool_param,
             config.list_param);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "dr_server_node");
    dynamic_reconfigure::Server<dyna_cfg_pkg::drConfig> server;
    server.setCallback(boost::bind(&drCb,_1,_2));
    ros::spin();
    return 0;
}
