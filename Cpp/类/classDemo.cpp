#include <iostream>
#include <string>
using namespace std;

// 设计立方体类
// 求出立方体面积与体积
// 分别用全局函数和成员函数判断两个立方体是否相等

// 创建立方体类
// 设计属性
// 设计行为，获取立方体面积和体积
// 分别利用全局函数和成员函数  判断立方体是否相等

class Cube
{
    // 行为
    // 设置、获取： 长，宽，高
    // 获取立方体面积
    // 获取立方体体积
public:
    // 设置长
    void setL(int l)
    {
        m_L = l;
    }
    // 获取长
    int getL()
    {
        return m_L;
    }
    // 设置宽
    void setW(int w)
    {
        m_W = w;
    }
    // 获取宽
    int getW()
    {
        return m_W;
    }   
    // 设置高
    void setH(int h)
    {
        m_H = h;
    }
    // 获取高
    int getH()
    {
        return m_H;
    }
    // 获取立方体面积
    int calculateS()
    {
        return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
    }
    // 获取立方体体积
    int calculateV()
    {
        return m_L * m_W * m_H;
    }
    // 利用成员函数判断两个立方体是否相等
    // 自身的变量和传进来的class做判断
    bool isSameByClass(Cube &c)
    {
        if(m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    // 属性
    int m_L;
    int m_W;
    int m_H;
};

// 使用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2)
{
    if(c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main(int argc, char *argv[])
{
    Cube c1;
    c1.setW(10);
    c1.setL(10);
    c1.setH(10);
    cout << "c1 的面积为： " << c1.calculateS() << endl;
    cout << "c1 的体积为： "<< c1.calculateV() << endl;

    // 创建第二个立方体
    Cube c2;
    c2.setW(10);
    c2.setL(10);
    c2.setH(11);
    cout << "c2 的面积为： " << c2.calculateS() << endl;
    cout << "c2 的体积为： "<< c2.calculateV() << endl;

    // 利用全部函数判断，c1与c2都是未知变量，需要都作为参数传递进去
    bool ret = isSame(c1, c2);
    if(ret)
    {
        cout << "全局函数判断-c1和c2相等" << endl;
    }
    else
    {
        cout << "全局函数判断-c1和c2不等" << endl;
    }
    // 利用成员函数判断, c1是已知变量，只需要再传入一个未知变量即可
    bool ret2 = c1.isSameByClass(c2);
    if(ret2)
    {
        cout << "成员函数判断-c1和c2相等" << endl;
    }
    else
    {
        cout << "成员函数判断-c1和c2不等" << endl;
    }
    return 0;
}