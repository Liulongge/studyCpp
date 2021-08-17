#include<iostream>

using namespace std;

// 函数重载注意事项：
// 1.引用作为函数重载条件
// 2.函数重载中默认参数

void func(int &a)
{
    cout << "func(int &a) 的调用" << endl;
}

void func(const int &a)
{
    cout << "const func(int &a) 的调用" << endl;
}

void func2(int a, int b = 10)
{
    cout << "func2(int a, int b) 的调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a) 的调用" << endl;
}

int main()
{
    int a = 10;
    // func(int &a) 的调用
    func(a);
    // const func(int &a) 的调用
    func(20);

    // 有多个 重载函数 "func2" 实例与参数列表匹配
    // 当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
    // func2(2);
    return 0;
}