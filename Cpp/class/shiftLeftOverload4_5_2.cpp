#include <iostream>
#include <string>
using namespace std;

// 重载运算法
// 运算符重载概念：对已有的运算符重新进行定义，赋予其另外一种功能，以适应不同数据类型

// 对于内置的数据类型，编译器知道如何进行运算
// int a = 10;
// int b = 10;
// int c = a + b;

// ###### 左移运算符重载 ######

// 作用：可以输出自定义数据类型

class Person
{
    // 友元技术访问私有变量
    friend ostream &operator<<(ostream &cout , Person &p);
public:
    Person(int a, int b)
    {
        m_A = a;
        m_B = b;
    }
private:
    // 利用成员函数重载 左移运算符
    // 通常不会使用成员函数重载 << 左移运算符， 因为无法实现 cout 在左边
    // void operator<<(cout &p)
    // {

    // }
    int m_A;
    int m_B;
};

// 只能使用全局函数 重载左移运算符
// 本质 operator << (cout, p), 简化 cout << p
ostream &operator<<(ostream &cout , Person &p)
{
    cout << "m_A = " << p.m_A << "; m_B = " << p.m_B;
    return cout; // 链式编程，需要返回对象
}

void test01()
{
    Person p(10, 10);
    cout << p << "; Hello World" << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}