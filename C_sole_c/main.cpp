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
    Point_2d operator+(Point_2d & obj)const;    //operator sum
    inline double Get_X()const;                 //return X
    inline double Get_Y()const;                 //return Y
    inline void Set_X();                        //set X
    inline void Set_Y();                        //set Y
    friend std::ostream & operator<<(std::ostream & os, Point_2d & obj);    //output operator


};
Point_2d::Point_2d(): x(0), y(0){}               //default constructor (realisation)

Point_2d::Point_2d(double v_x, double v_y)      //constructor with parametres   (realisation)
{
    this->x = v_x;
    this->y = v_y;
}
Point_2d::Point_2d(const Point_2d &obj): x(obj.x), y(obj.y){}         //constructor copy (realisation)


inline double Point_2d::Get_X()const
{
    return this->x;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Point_2d lol;
    Point_2d lol2(lol);
    std::cout<<lol.Get_X()<<std::endl;
    return a.exec();
}
