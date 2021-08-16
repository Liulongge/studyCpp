#include<iostream>

using namespace std;

// 引用
// 作用：给变量起别名
// 语法：数据类型 &别名 = 原名

// 引用基本语法
void test01()
{
    cout << " -------- test01 -------- "<< endl;
    int a = 10;

    // 创建引用
    int &b = a;
    cout << "a = "<< a << ", a 地址 = " << &a << endl;
    cout << "b = "<< b << ", b 地址 = " << &b << endl;

    b = 100;
    cout << "a = "<< a << ", a 地址 = " << &a << endl;
    cout << "b = "<< b << ", b 地址 = " << &b << endl;
}

// 引用注意事项
// 引用必须初始化
// 引用在初始化后，不可改变
void test02()
{
    cout << " -------- test02 -------- "<< endl;
    // int &cc; // 错误，引用必须初始化
    int a = 10;
    int &b = a;
    int c = 20;
    b = c; // 赋值操作，不是更改引用。

    cout << "a = "<< a << ", a 地址 = " << &a << endl;
    cout << "b = "<< b << ", b 地址 = " << &b << endl;
    cout << "c = "<< c << ", c 地址 = " << &c << endl;
}

// 引用作为函数参数
// 函数传参时，可以利用引用的家属让形参修饰实参
// 优点：可以简化指针修改实参，用引用替换指针
// 总节：通过引用参数产生的效果同按地址传递效果一样，引用的语法更清晰简单。

// 交换函数
// 1.值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
// 2.地址传递
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3.引用传递
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void test03()
{
    int a = 10;
    int b =20;
    mySwap01(a, b);
    cout << "值传递，形参不会修饰实参" << endl;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;

    mySwap02(&a, &b);
    cout << "地址传递，形参会修饰实参" << endl;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;

    mySwap03(a, b);
    cout << "引用传递，形参会修饰实参" << endl;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
}

// 引用做函数返回值
void test04()
{

}

int main()
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}