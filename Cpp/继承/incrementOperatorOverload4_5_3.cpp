#include <iostream>
#include <string>
using namespace std;

// 重载运算法
// 运算符重载概念：对已有的运算符重新进行定义，赋予其另外一种功能，以适应不同数据类型

// 对于内置的数据类型，编译器知道如何进行运算
// int a = 10;
// int b = 10;
// int c = a + b;

// ###### 递增运算符重载 ######
// 作用：通过重载递增运算符，实现自己的整形数据

class MyInterger
{
    friend ostream &operator<<(ostream &cout , MyInterger myint);
public:
    MyInterger()
    {
        m_Num = 0;
    }

    // 重载运算++ 运算符
    // 1.重载前置递增 ++
    // 2.重载后置递增 ++
    // 返回引用 是为了一直对一个数据进行操作

    // ###### 前置递增 ######
    // 前置递增返回引用
    MyInterger& operator++()
    {
        // 先进行++运算
        m_Num ++;
        // 再将自身做一个返回
        return *this;
    }

    // ###### 后置递增 ######
    // int 代表站位参数 用于区分前置和后置递增
    // 后置递增 返回值
    MyInterger operator++(int)
    {
        // 先 记录当时结果
        MyInterger temp = *this;
        // 后 递增操作
        m_Num ++;
        // 最后 返回
        return temp;
    }
private:
    int m_Num;
};

// 只能使用全局函数 重载左移运算符, 需要将 cout 写在左边，成员函数无法做到
// 本质 operator << (cout, p), 简化 cout << p
ostream &operator<<(ostream &cout , MyInterger myint)
{
    cout << "myint.m_Num = " << myint.m_Num;
    return cout; // 链式编程，需要返回对象
}

// 前置递增
void test01()
{
    MyInterger myint;
    cout << ++(++myint) << endl;
}
// 后置递增
void test02()
{
    MyInterger myint;
    cout << ++myint << endl;
}
int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}