#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "map_pub_node");
    ros::NodeHandle nh;
    ros::Publisher pub_map = nh.advertise<nav_msgs::OccupancyGrid>("/map", 1);
    ros::Rate rate(10);
    while (ros::ok())
    {
        nav_msgs::OccupancyGrid map;
        map.header.frame_id = "map";
        map.header.stamp = ros::Time::now();
        map.info.height = 2;
        map.info.width = 4;
        map.info.origin.position.x = 1.0;
        map.info.origin.position.y = 0;
        map.info.resolution = 1.0;
        map.data.resize(4 * 2);
        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
            {
                map.data[i] = 100;
            }
            else
            {
                map.data[i] = 0;
            }
        }
        pub_map.publish(map);
        rate.sleep();
    }
    return 0;
}
