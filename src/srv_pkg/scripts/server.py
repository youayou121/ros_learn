#!/usr/bin/env python3
import rospy
from srv_pkg.srv import *
def doNum(request=AddIntsRequest()):
    num1 = request.num1
    num2 = request.num2
    response=AddIntsResponse()
    response.sum = num1+num2;
    sum = response.sum
    rospy.loginfo("收到的数据为：num1 = %d,num2 = %d。",num1,num2)
    rospy.loginfo("求和的结果为：sum = %d 。",sum);
    return response
    
def main():
    rospy.init_node("server_node_py")
    server = rospy.Service("add_ints_py",AddInts,doNum)
    rospy.spin()
    
if __name__ == '__main__':
    main()
    