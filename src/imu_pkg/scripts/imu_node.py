#!/usr/bin/env python3
import rospy
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion
from geometry_msgs.msg import Twist
pub_vel = rospy.Publisher("cmd_vel",Twist,queue_size=1)
def imu_cb(imu=Imu()):
    if imu.orientation_covariance[0]<0:
        return
    quaternion = [ 
        imu.orientation.x,
        imu.orientation.y,
        imu.orientation.z,
        imu.orientation.w]
    roll,pitch,yaw = euler_from_quaternion(quaternion)
    rospy.loginfo("滚转:%.2f,俯仰:%.2f,偏航:%.2f",roll,pitch,yaw)
    target_yaw = -1;
    diff_angle = target_yaw - yaw
    cmd_vel = Twist()
    cmd_vel.angular.z = diff_angle*0.5
    pub_vel.publish(cmd_vel)
    
def main():
    rospy.init_node("imu_node_py")
    sub_imu = rospy.Subscriber("imu/data",Imu,imu_cb,queue_size=1)
    rospy.spin()
if __name__ == '__main__':
    main()
    