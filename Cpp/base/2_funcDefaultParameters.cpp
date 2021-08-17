#include<iostream>

using namespace std;

// 函数默认参数
// 在C++中，函数的形参列表中的形参是可以有默认值的
// 语法 返回值类型 函数名 (参数 = 默认值) {}
// 注意：如果从某个位置开始已经有了默认参数，那么从这个位置开始，从左到右都必须有默认值
// 声明和实现只能有一个有默认参数，（容易产生二义性）。如果函数的声明有了默认参数，函数的实现就不能有默认参数。


// 如果自己传入数据，则使用传入数据，否则使用默认值
int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

// 如果函数的声明有了默认参数，函数的实现就不能有默认参数
int func2(int a, int b = 10, int c = 10);
int func2(int a, int b, int c)
{
    return a + b + c;
}


int main()
{
    cout << "func(1, 2, 3) = " << func(1, 2, 3) << endl;
    cout << "func(1) = " << func(1) << endl;
    cout << "func(1, 30) = " << func(1, 30) << endl;

    cout << "func2(1,2) = " << func2(1,2) << endl;
    return 0;
}