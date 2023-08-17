#!/usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String
from qq_msgs.msg import Carry
def main():
    rospy.init_node("chao_node_py")
    pub = rospy.Publisher("kaiheiqunpy",Carry,queue_size=1)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        msg = Carry()
        msg.grade = "王者"
        msg.star = 50
        msg.data = "我带飞py"
        pub.publish(msg)
        rate.sleep()
if __name__ == '__main__':
    main()
    