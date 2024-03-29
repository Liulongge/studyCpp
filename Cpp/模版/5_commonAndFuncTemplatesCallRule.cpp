#include<iostream>

using namespace std;
// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// C++另一种编程思想就是 泛型编程 ，主要利用的技术的 模板
// C++提供两种模板机制：1.函数模板、2.类模板

// 注意事项
// 自动推类型推导，必须推导出一致的数据类型 T 才可以使用
// 摸版必须要确定出 T 的数据类型，才可以使用

// 普通函数与模板函数区别
// 1.普通函数调用时发生自动类型转换（隐式类型转换）
// 2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
// 3.如果利用显示指定类型方式 "<类型>"，明确告诉，转换为该类型，可以发生隐式类型转换

// 调用规则如下:
// 1.如果 函数模板 和 普通函数 都可以实现，优先调用普通函数
// 2.可以通过 空模板参数列表 来强调调用函数模板
// 3.函数模板也可以发生重载
// 4.如果函数模板可以产生更好的匹配，有限调用函数模板

// ######## 既然已经提供了函数模板，最好不要提供不同函数，否则会出现二义性 ########


// 普通函数
void myPrint(int a, int b)
{
    cout << "调用的普通函数" << endl;
}

// 函数模板
template<typename T>
void myPrint(T a, T b)
{
    cout << "调用的函数模板" << endl;
}

// 函数模板重载
template<typename T>
void myPrint(T a, T b, T c)
{
    cout << "调用的函数模板重载" << endl;
}

void test01()
{
    int a = 10;
    int b = 20;
    int c = 30;
    // 3.函数模板也可以发生重载
    myPrint(a, b);          // 调用的普通函数, 1.如果 函数模板 和 普通函数 都可以实现，优先调用普通函数
    myPrint<>(a, b);        // 调用的函数模板, 2.可以通过 空模板参数列表 来强调调用函数模板
    myPrint<float>(a, b);   // 调用的函数模板
    myPrint(a, b, c);       //  用的函数模板重载, 3.函数模板也可以发生重载

    float d = 30.0f;
    float e = 40.0f;
    myPrint(d, e);          // 调用的函数模板, 4.如果函数模板可以产生更好的匹配，有限调用函数模板
}

int main()
{
    test01();
    return 0;
}