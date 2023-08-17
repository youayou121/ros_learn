#!/usr/bin/env python3
#coding=utf-8
import rospy
from std_msgs.msg import String
from qq_msgs.msg import Carry
def chao_cb(msg):
    rospy.loginfo(msg.data)
    
def yao_cb(msg):
    rospy.logwarn(msg.data)
    
def main():
    rospy.init_node("ma_node_py")
    sub_py = rospy.Subscriber("kaiheiqunpy",Carry,chao_cb)
    # sub_cpp = rospy.Subscriber("kaiheiqun",String,yao_cb)
    rospy.spin()
if __name__ == '__main__':
    main()
    