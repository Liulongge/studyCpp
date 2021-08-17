#include<iostream>

using namespace std;

// 函数占位参数
// 形参只写一个数据类型，就是占位参数
// C++中函数的形参列表里可以有占位参数，用来占位，调用函数时必须填补该位置
// 语法： 返回值类型 函数名 (数据类型) {}
// 占位参数可以有默认参数 void func(int a, int = 10);

void func(int a, int)
{
    cout << "this is func" << endl;
}

int main()
{
    func(10, 10);
    return 0;
}