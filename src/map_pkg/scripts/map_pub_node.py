#!/usr/bin/env python3

import rospy
from nav_msgs.msg import OccupancyGrid


def main():
    rospy.init_node("map_pub_node")
    pub_map = rospy.Publisher("map",OccupancyGrid,queue_size=1)
    map = OccupancyGrid()
    map.header.frame_id = "map"
    map.header.stamp = rospy.Time.now()
    map.info.height = 2
    map.info.width = 4
    map.info.resolution = 1.0
    map.info.origin.position.x = -1.0
    map.info.origin.position.y = 0
    map.data = [0]*4*2
    for i in range(0,7,1):
        if i<4:
            map.data[i] = 0
        else:
            map.data[i] = 100
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        pub_map.publish(map)
        rate.sleep()

if __name__ == '__main__':
    main()
    