#include <ros/ros.h>
#include <pluginlib/class_loader.h>
#include <plugin_pkg/dbx_base.h>

// 创建类加载器
// 使用类加载器实例化某个插件对象
// 使用插件

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    pluginlib::ClassLoader<dbx_base_ns::DbxBase> loader("plugin_pkg", "dbx_base_ns::DbxBase");
    boost::shared_ptr<dbx_base_ns::DbxBase> san = loader.createInstance("Dbx/SanBian");
    boost::shared_ptr<dbx_base_ns::DbxBase> si = loader.createInstance("dbx_plugins_ns::SiBian");
    san->init(3.5);
    si->init(3.5);
    double san_length = san->getLength(0);
    double san_area = san->getArea();
    double si_length = si->getLength(1);
    double si_area = si->getArea();
    ROS_INFO("\n三角形周长为%.2f,面积为%.2f\n正方形周长为%.2f,面积为%.2f\n", san_length,san_area, si_length,si_area);
    return 0;
}
