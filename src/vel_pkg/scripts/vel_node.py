#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Twist
def main():
    rospy.init_node("vel_node_py")
    pub_vel = rospy.Publisher("cmd_vel",Twist,queue_size=1)
    msg = Twist()
    msg.linear.x = 1
    msg.angular.z = 2
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        pub_vel.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    main()
    