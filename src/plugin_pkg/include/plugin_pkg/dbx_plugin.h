#ifndef DBX_PLUGIN_H_
#define DBX_PLUGIN_H_
#include <plugin_pkg/dbx_base.h>
namespace dbx_plugins_ns
{
    class SanBian : public dbx_base_ns::DbxBase
    {
    private:
        double side_length;

    public:
        SanBian();
        void init(double side_length);
        double getLength(int i);
        double getArea();
        ~SanBian();
    };

    SanBian::SanBian()
    {
        side_length = 0;
    }
    void SanBian::init(double side_length)
    {
        this->side_length = side_length;
    }
    double SanBian::getLength(int i)
    {
        return 3 * this->side_length * i;
    }
    double SanBian::getArea()
    {
        return this->side_length*(this->side_length/2*pow(this->side_length,1/3))/2;
    }
    SanBian::~SanBian()
    {
    }

    class SiBian : public dbx_base_ns::DbxBase
    {
    private:
        double side_length;

    public:
        SiBian();
        void init(double side_length);
        double getLength(int i);
        double getArea();
        ~SiBian();
    };

    SiBian::SiBian()
    {
        this->side_length = 0;
    }
    void SiBian::init(double side_length)
    {
        this->side_length = side_length;
    }
    double SiBian::getLength(int i)
    {
        return 4 * side_length * i;
    }
        double SiBian::getArea()
    {
        return this->side_length*this->side_length;
    }
    SiBian::~SiBian()
    {
    }

}

#endif