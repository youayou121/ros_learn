#ifndef DBX_BASE_H_
#define DBX_BASE_H_
namespace dbx_base_ns
{
    /*
        基类中必须包含无参构造
    */
    class DbxBase
    {
    protected:
        DbxBase(){}

    public:
        virtual double getLength(int i)=0;
        virtual double getArea()=0;
        virtual void init(double side_length) = 0;
        ~DbxBase(){}
    };
}
#endif