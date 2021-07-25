#include "circle.h"
// 类的成员函数的实现在.cpp中

// 设置半径
void Circle::setR(int r)    // Circle 命名空间下的xxx
{
    m_R = r;                // m_R为 Circle类中私有变量，因此需要在setR指定 Circle::setR Circle 命名空间下的成员函数
}
// 获取半径
int Circle::getR()
{
    return m_R;
}
// 设置圆心
void Circle::setCenter(Point center)
{
    m_Center = center;
}
// 获取圆心
Point Circle::getCenter()
{
    return m_Center;
}