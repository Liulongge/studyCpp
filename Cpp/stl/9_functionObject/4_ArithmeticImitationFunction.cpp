#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

// 内建函数对象
// 概念：STL中内建一些函数对象

// 分类：
// 算数仿函数
// 关系仿函数
// 逻辑仿函数

// 用法：
// 这些仿函数所产生的对象，用法和一般函数完全相同
// 使用内建函数对象，需要引入头文件 #include<functional>

// 算数仿函数：实现四则运算，
// 其中 negate 是一元运算，其他都是二元运算
// 仿函数原型：
// template<class T> T plus<T>          加法仿函数
// template<class T> T minus<T>         减法仿函数
// template<class T> T multiplies<T>    乘法仿函数
// template<class T> T divides<T>       除法仿函数
// template<class T> T modulus<T>       取模仿函数
// template<class T> T negate<T>        取反仿函数

// negate 取反仿函数，一元仿函数
// plus 加法仿函数，二元仿函数
void test01()
{
    negate<int> n;
    cout << "取反仿函数n(50)：" << n(50) << endl;

    // 只允许同类型运算，模板中只需要写一个 int 类型
    plus<int> n2;
    cout << "加法仿函数n2(10, 20)：" << n2(10, 20)<< endl;
}

int main()
{
    test01();
    return 0;
}