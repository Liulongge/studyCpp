#pragma once
#include "point.h"

// 类的声明在.h中

class Circle
{
public:
    // 设置半径
    void setR(int r);
    // 获取半径
    int getR();
    // 设置圆心
    void setCenter(Point center);
    // 获取圆心
    Point getCenter();
private:
    // 半径
    int m_R;
    // 在类中可以让另一个类 作为成员
    Point m_Center;   // 圆心
};