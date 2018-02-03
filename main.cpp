#include <QCoreApplication>
#include <iostream>
#include <vector>

class Point_2d
{
    double x;                                    //coord X
    double y;                                    //coord Y
public:
    Point_2d();                                 //default constructor
    Point_2d(double v_x, double v_y);           //constructor with parametres
    Point_2d(const Point_2d & obj);                   //constructor copy
    Point_2d operator+(const Point_2d & obj)const;    //operator sum
    Point_2d operator+= (const Point_2d & obj);         //operator +=
    inline double Get_X()const;                 //return X
    inline double Get_Y()const;                 //return Y
    inline void Set_X(const double val_x);                        //set X
    inline void Set_Y(const double val_y);                        //set Y
    friend std::ostream & operator<<(std::ostream & os, const Point_2d & obj);    //output operator


};
Point_2d::Point_2d(): x(0), y(0){}               //default constructor (realisation)

Point_2d::Point_2d(double v_x, double v_y)      //constructor with parametres   (realisation)
{
    this->x = v_x;
    this->y = v_y;
}
Point_2d::Point_2d(const Point_2d &obj): x(obj.x), y(obj.y){}         //constructor copy (realisation)



inline double Point_2d::Get_X()const                            //getter X (realisation)
{
    return this->x;
}
inline double Point_2d::Get_Y()const                             //getter Y (realisation)
{
    return this->y;
}
inline void Point_2d::Set_X(const double val_x)                 //setter X (realisation)
{
    this->x=val_x;
}
inline void Point_2d::Set_Y(const double val_y)                    //setter Y (realisation)
{
    this->y=val_y;
}

Point_2d Point_2d::operator +(const Point_2d & obj)const            //overload operator summ (realisation)
{
    Point_2d temp;
    temp.x=this->x+obj.x;
    temp.y=this->y+obj.y;
    return temp;
}
std::ostream & operator<<(std::ostream & os, const Point_2d & obj)       //overload operator output << (realisation)
{
    os<<"x="<<obj.Get_X()<<"; y="<<obj.Get_Y()<<";";
    return os;
}
Point_2d Point_2d::operator +=(const Point_2d & obj)                    //overload operator += (realisation)
{
    this->x+=obj.x;
    this->y+=obj.y;
    return *this;
}

template <typename T>
void Print_Vector_Data(std::vector<T> vect)                     //template for print vector data
{
    for(auto i:vect)
        std::cout<<i<<std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<Point_2d> V_2dPoint({{5,6},{5,3},{10.5,13.643}});          //create vector of objects
    Print_Vector_Data(V_2dPoint);                                          //print Vector Data

    Point_2d summ;                                                          //summ all elements in vector
    for(auto i:V_2dPoint)
        summ+=i;
    std::cout<<summ<<std::endl;                                             //print summ


    return a.exec();
}
