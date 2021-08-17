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
    cout << " -------- test03 -------- "<< endl;
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
// 不要返回局部变量的引用
// 函数调用可以作为左值
int& test04()
{
    cout << " -------- test04 -------- "<< endl;
    static int a = 10;
    return a;
}

// 引用的本质：引用的本质在C++内部实现是一个指针常量
// 发现是引用，转换为 int* const ref = & a;
void func(int& ref)
{
    ref = 100;  // ref是引用，转换为 *ref = 10;
}

void test05()
{
    cout << " -------- test05 -------- "<< endl;
    int a = 10;

    int& ref = a;  // 自动转换为 int* const ref = & a；指针常量是指针指向不可更改，也说明为什么引用不可更改
    ref = 20;      // 内部发现ref是引用，自动帮我们转换为： *ref = 20;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    func(a);
}

// 常量引用
// 作用：常量引用主要用来修饰形参，防止误操作
// 在函数形参列表中，可以加 const 修饰形参，防止形参改变实参
void showValue(const int  &val)
{
    cout << "val = " << val << endl; 
}

void test06()
{
    cout << " -------- test06 -------- "<< endl;
    int a = 100;
    // 加上 const 之后，编译器将代码修改为 int temp = 10, const int & ref = temp;
    const int & ref = 10;
    cout << "ref = " << ref << endl;

    showValue(a);
}

int main()
{
    test01();
    test02();
    test03();
    cout << test04() << endl;
    test04() = 1000;  // 如果函数调用的返回值是引用，这个函数调用可以作为左值
    cout << test04() << endl;
    test05();
    test06();
    return 0;
}