// g++ point.cpp circle.cpp classCirclePoint.cpp -o demo

#include <iostream>
#include <string>
#include "circle.h"
#include "point.h"
using namespace std;

// 设计一个圆类和一个点类
// 判断圆和点的关系
// 点到圆心距离：（x1 - x2)^2 + (y1 - y2)^2    ?     r^2
// == 半径 点在圆上
// >  半径 点在圆外
// <  半径 点在园内

void isInCircle(Circle &c, Point &p)
{
    // 计算两点之间距离的平方
    int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + \
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

    int rDistance = c.getR() * c.getR();

    // 判断关系
    if(distance == rDistance)
    {
        cout << "点在圆上" << endl;
    }
    else if(distance > rDistance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }

}
int main(int argc, char *argv[])
{
    // 创建一个圆
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);

    // 创建一个点
    Point p;
    p.setX(10);
    p.setY(100);

    // 判断
    isInCircle(c,p);

    return 0;
}
