#include <iostream>
#include <string>
using namespace std;

// 多态，多种形态
// 多态是C++面向对象三大特征之一
// 静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
// 动态重载：派生类 和 虚函数实现运行时多态

// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 纯虚函数语法：virtual 返回值类型 函数名 （参数列表） = 0；

// 当类中有了纯虚函数，这个类也称为 ####### 抽象类 ######
// 抽象类特点：
// 1.无法实例对象
// 2.子类必须重写抽象类中的虚函数，否则也属于抽象类

// 纯虚函数和抽象类
class Base
{
public:
    // 纯虚函数
    // 只要有一个纯虚函数，这个类就是 抽象类
    // 抽象类特点：
    // 1.无法实例对象
    // 2.子类必须重写抽象类中的虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
public:
    void func()
    {
        cout << "func 函数调用" << endl;
    }
};

void test01()
{
    // Base b;    // 抽象类无法实例化，不管在堆区或者栈区
    // new Base;
    // Son s;        // 子类必须重写父类中纯虚函数

    Base *base = new Son;
    base->func();
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}