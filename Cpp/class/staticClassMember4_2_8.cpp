
#include <iostream>
#include <string>
using namespace std;

// 静态成员
// 静态成员就是在成员变量和成员函数前面加上关键字 static，称为静态成员

// 静态成员分为：
// 1. 静态成员变量
// 所有对象共享同一份数据
// 在编译阶段分配内存
// 类内声明，类外初始化

// 2. 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Persion
{
public:
    // 静态成员函数
    static void func()
    {
        // 静态成员函数可以访问 静态成员变量
        m_A = 100; 
        // 静态成员函数，不可以访问非静态成员变量
        // 静态成员变量被所有对象共享，无法区分到底是哪一个函数的 m_B，因此无法访问。
        // m_B = 10;
        cout << "static void func 调用" << endl;
    }

    // 静态成员变量
    static int m_A; 
    // 非静态成员变量
    int m_B;

    // 静态成员函数也是有访问权限的，private 在类外访问不到私有静态成员函数
private:
    static void func2()
    {
        cout << "static void func2 调用" << endl;
    }
};


void test01()
{
    // 1.通过对象访问
    Persion p;
    p.func();
    // 2.通过类名访问, func不属于某一个对象，大家共用一个，不需要创建对象，即可访问。
    Persion::func();

    // 类外不可以访问私有静态成员函数
    // Persion::func2();
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}
