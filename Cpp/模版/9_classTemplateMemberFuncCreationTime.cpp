#include<iostream>
#include<string>
using namespace std;

// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// 类模板中成员函数和普通类中成员函数创建时机是有区别的
// 普通类中的成员函数一开始就可以创建
// 类模板中的成员函数在调用时才创建

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};

template<typename T>
class MyClass
{
public:
    T obj;
    // 类模板中成员函数，一开始不会创建，只有被调用时候才会被创建
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }
};

void test01()
{
    MyClass<Person1> m;
    m.func1();
    // m.func2();  // 编译出错，说明函数调用才会去创建成员函数

    MyClass<Person2> m2;
    // m2.func1(); // 编译出错，说明函数调用才会去创建成员函数
    m2.func2();
}


int main()
{
    test01();
    return 0;
}