#!/usr/bin/env python3
import rospy
from action_pkg.msg import *
from actionlib import SimpleActionServer

class MyAction:
    def __init__(self):
        self.server = SimpleActionServer("add_ints_py",AddIntsAction,self.sasCb,False)
        self.server.start()
        rospy.loginfo("服务端初始化成功---")
    def sasCb(self,goal=AddIntsGoal):
        num1 = goal.num1
        num2 = goal.num2
        result = 0
        rate = rospy.Rate(10)
        rospy.loginfo("正在进行运算---")
        for i in range(num1,num2,1):
            result += i
            rate.sleep()
            fb = AddIntsFeedback()
            fb.progress_bar = (i - num1)/(num2 - num1)
            self.server.publish_feedback(fb)
        rs = AddIntsResult()
        rs.result = result
        rospy.loginfo("运算成功!")
        self.server.set_succeeded(rs)
    pass

def main():
    rospy.init_node("server_node_py")

    action = MyAction()

    rospy.spin()
    

if __name__ == '__main__':
    main()
    