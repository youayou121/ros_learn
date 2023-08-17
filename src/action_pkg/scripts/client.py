#!/usr/bin/env python3
import rospy
from action_pkg.msg import *
from actionlib import *
def doneCb(status,result=AddIntsResult):
    if status == GoalStatus.SUCCEEDED:
        rospy.loginfo("计算结果为：result = %d",result.result)
    else:
        rospy.logerr("计算错误！")
    
def activeCb():
    rospy.loginfo("服务端已经接收数据")

def feedbackCb(feedback = AddIntsFeedback()):
    rospy.loginfo("当前进度：%.3f",feedback.progress_bar)

def main():
    rospy.init_node("client_node_py")
    client = SimpleActionClient("add_ints_py",AddIntsAction)
    client.wait_for_server()
    goal = AddIntsGoal()
    goal.num1 = 0
    goal.num2 = 10
    client.send_goal(goal,doneCb,activeCb,feedbackCb)
    rospy.spin()
if __name__ == '__main__':
    main()
    