#!/usr/bin/env python3
import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
pub_vel = rospy.Publisher("cmd_vel",Twist,queue_size=1)
def lidar_cb(scan):
    mid = 180
    dist = scan.ranges[mid]
    rospy.loginfo("正前方障碍物距离为:ranges[%d]=%.2f",mid,dist)
    cmd_vel = Twist()
    if dist>1.5:
        cmd_vel.linear.x = 0.5
        cmd_vel.angular.z = 0
    else:
        cmd_vel.linear.x = 0
        cmd_vel.angular.z = 1
    pub_vel.publish(cmd_vel)
        
    
def main():
    rospy.init_node("lidar_node_py")
    sub_scan = rospy.Subscriber("scan",LaserScan,lidar_cb,queue_size=1)
    rospy.spin()
if __name__ == '__main__':
    main()
    