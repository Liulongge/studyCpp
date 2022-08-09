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

// 总结
// 使用模板时必须确定出通用数据类型 T, 并且能够推导出一致的类型

template<typename T> // typename 可以替换成 class
// 自动推类型推导，必须推导出一致的数据类型 T 才可以使用, 即 a 与 b 数据类型必须一样
void mySwap(T& a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T> 
// note: candidate template ignored: couldn't infer template argument 'T'
// 摸版必须要确定出 T 的数据类型，才可以使用
// func<int>();
void func()
{
    cout << "func 调用 " << endl;
}

void test01()
{
    int a = 10;
    int b = 20;
    mySwap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
}

int main()
{
    test01();
    // func();
    func<int>();
    return 0;
}