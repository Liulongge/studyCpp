#include <iostream>
#include <string>
using namespace std;

// 重载运算法
// 运算符重载概念：对已有的运算符重新进行定义，赋予其另外一种功能，以适应不同数据类型

// 对于内置的数据类型，编译器知道如何进行运算
// int a = 10;
// int b = 10;
// int c = a + b;

// ###### 函数调用运算符重载 ######
// 函数调用运算符（）也可以重载
// 由于重载后使用的方式非常像函数的调用，因此称为 仿函数
// 仿函数没有固定写法，非常灵活

// 打印输出的类
class MyPrint
{
public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }

};

// 加法类
class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test01()
{
    MyPrint myprint;
    myprint("Hello World"); // 又有使用起来非常类似于函数调用，因此称为仿函数
}

void test02()
{
    MyAdd myadd;
    int ret = myadd(100, 100);
    cout << "ret = " << ret << endl;

    // 匿名函数对象
    // 创建匿名对象 MyAdd()
    // 匿名对象使用完后会立即释放
    cout << MyAdd()(100, 100) << endl;
}

int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}