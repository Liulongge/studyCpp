#include<iostream>

using namespace std;
// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// C++另一种编程思想就是 泛型编程 ，主要利用的技术的 模板
// C++提供两种模板机制：1.函数模板、2.类模板

// 函数模板语法

// 函数模板作用
// 建立一个通用函数，其函数返回值类型 和 形参类型可以不具体指定 用一个 虚拟的类型 来表示

// 语法
// template<tppename T>
// 函数声明或定义
// void func(int a)

// 解释：
// temolate -- 声明创建模板
// typename -- 表明其后面的符号是一种数据类型，可以用 class 替换
// T -- 通用的数据类型名称可以替换，通常为大写字母

// 使用：
// 1.自动类型推导
// 2.显示指定数据类型： mySwap<double>(c, d)

// 目的：
// 提高代码复用性，将类型模板化

// 交换两个整形函数
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 交换两个浮点型函数
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// 交换......

// 模板技术
template<typename T> // 声明一个模板，告诉编译器代码中紧跟的 T 不要报错，T 是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    cout << "-------- 普通方法实现 -------" << endl;
    int a = 10;
    int b = 20;
    swapInt(a, b);
    cout << "a = " << a << "; b = " << b << endl;

    double c = 1.1;
    double d = 1.2;
    swapDouble(c, d);
    cout << "c = " << c << "; d = " << d << endl;

    cout << "-------- 函数模板实现 -------" << endl;
    // 利用函数模板交换
    // 两种方式使用函数模板

    // 1.自动类型推导
    a = 10;
    b = 20;
    mySwap(a, b);
    cout << "a = " << a << "; b = " << b << endl;

    // 2.显示指定类型
    c = 1.1;
    d = 1.2;
    mySwap<double>(c, d);
    cout << "c = " << c << "; d = " << d << endl;
}

int main()
{
    test01();
    return 0;
}