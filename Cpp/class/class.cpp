#include <iostream>

using namespace std;

const double PI = 3.14;

// 代表设计一个圆类
class Circle
{
    // 访问权限
    // 公共权限
    // 默认为私有成员
public:
    int m_r;

    // 行为
    // 获取圆的周长
    double calculateZC()
    {
        return 2 * PI * m_r;
    }
};

int main(int argc, char *argv[])
{
    // 通过圆类 创建具体对象
    // 实例化 通过一个类 创建一个对象的过程
    Circle cl;

    // 给圆对象属性赋值
    cl.m_r = 10;

    cout << "圆的周长为：" << cl.calculateZC() << endl;

    return 0;
}