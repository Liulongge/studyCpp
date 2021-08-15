#include<iostream>
#include<map>
#include<string>

using namespace std;

// 函数对象
// 概念：
// 重载函数调用操作符的类，其对象常称为 函数对象
// 函数对象使用重载()时，行为类似函数调用，也叫 仿函数

// 本质：
// 函数对象（仿函数）是一个类，不是一个函数

// 函数对象的使用：
// 特点：
// 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
// 3.函数对象可以作为参数传递

// 总结：仿函数语法十分灵活，没有固定写法

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        this->count ++;
    }
    int count = 0;
};

void doPrint(MyPrint & mp, string test)
{
    mp(test);
}

void test01()
{
    // 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
    MyAdd myadd;
    cout << myadd(10, 10) << endl;
}

void test02()
{
    // 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
    MyPrint myprint;
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    cout << "MyPrint调用次数为：" << myprint.count << endl; 
}

void test03()
{
    // 3.函数对象可以作为参数传递
    MyPrint myprint;
    doPrint(myprint, "hello c++");
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}