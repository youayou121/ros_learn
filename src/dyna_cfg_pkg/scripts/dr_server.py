#!/usr/bin/env python3
import rospy
from dyna_cfg_pkg.cfg import drConfig
from dynamic_reconfigure.server import Server

def drCb(config,level):
    rospy.loginfo("\nint_param被改为：%d \n double_param被改为：%f \n str_param被改为：%s \n bool_param被改为：%d \n list_param被改为：%d \n",
                  config.int_param,
                  config.double_param,
                  config.str_param,
                  config.bool_param,
                  config.list_param
                  )
    return config
def main():
    rospy.init_node("dr_server_node_py")
    server = Server(drConfig,drCb)

    rospy.spin()

if __name__ == '__main__':
    main()
    