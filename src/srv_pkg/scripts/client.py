#!/usr/bin/env python3
import rospy
from srv_pkg.srv import *
    
def main(argv):
    rospy.init_node("client_node_py")
    client = rospy.ServiceProxy("add_ints_py",AddInts)
    # client.wait_for_service()
    rospy.wait_for_service("add_ints_py")
    response = client.call(AddIntsRequest(int(argv[1]),int(argv[2])))
    rospy.loginfo("计算结果为：sum = %d",response.sum)
    
if __name__ == '__main__':
    if len(sys.argv)!=3:
        rospy.logwarn("参数个数不对!")
        exit(1)
    else:
        main(sys.argv)
        
    
    