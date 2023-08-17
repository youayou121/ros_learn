#!/usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String

def main():
    rospy.init_node("yao_node_py")
    pub = rospy.Publisher("daifeiqunpy",String,queue_size=1)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        msg = String()
        msg.data = "求带飞py"
        pub.publish(msg)
        rate.sleep()
if __name__ == '__main__':
    main()
    