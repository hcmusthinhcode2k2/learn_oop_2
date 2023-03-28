
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
//Class forward declaration (tham chieu vong)
class Point2D;
class Line2D;
//Class declaration
class Point2D {
    private:
        int _x;
        int _y;
    public: //getter setter
        int X(){return _x;}
        int Y(){return _y;}
        void setX(int value){ _x=value;}
        void setY(int value){ _y=value;}
    public: //construct ham tao
        Point2D();
        Point2D(int);
        Point2D(int,int);
        //~Point2D();
    public:
        string toString();
        float distanceTo(Point2D);
};
class Line2D {
private:
       Point2D _start;
       Point2D _end;
public:
       Point2D start() {return _start;}
       Point2D end() {return _end;}
       void setStart(Point2D value){ _start= value;}
       void setEnd(Point2D value){ _end= value;}
public:
        Line2D();
        Line2D(Point2D,Point2D);
        string toString();
        float length();  //Độ dài của đường thẳng

};
//In class exercise:
Line2D::Line2D() {

}
Line2D::Line2D(Point2D a,Point2D b)
{
    _start=a;
    _end=b;
}
string Line2D::toString() {
    stringstream writer;
    writer << "("<<_start.toString()<<","<<_end.toString()<<")";
    string result=writer.str();
    return result;
}
float Point2D::distanceTo(Point2D other)
{
    float result =0;
    int dx=this->_x-other._x;
    int dy=this->_y-other._y;
    result=sqrt(dx*dx+dy*dy);
    return result;
}
float Line2D::length()
{
    float result=0;
    result =_start.distanceTo(_end);
    return result;
}
//class implementation -cai dat thiet su
Point2D::Point2D() {
    _x=0;
    _y=0;
}
Point2D::Point2D(int i){
    _x=i;
    _y=i;
}
Point2D::Point2D(int a,int b)
{
    _x=a;
    _y=b;
}
string Point2D::toString() {
    stringstream out;

    out<<"("<<this->_x<<","<<this->_y<<")";
    string result=out.str();
    return result;
}
// Point2D::~Point2D()
// {
//     cout <<"Destruction of "<<this->toString()<<endl;
// }
int main()
{
   Point2D b(2,4);
   Point2D c(3);
   Line2D line(b,c);
   cout <<line.toString()<<endl;
   cout <<line.length()<<endl;
   return 0;
}