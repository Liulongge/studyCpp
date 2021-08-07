#pragma once

#include<iostream>
#include<string>
using namespace std;

// 类模板份文件编写
// 掌握类模板成员函数份文件编写产生的问题以及解决方式

// 问题：
// 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
// 解决：
// 解决方式1：直接包含.cpp文件
// 解决方式2：将声明和实现写在同一文件中，并更改后缀名为hpp，hpp是约定的名称，并不是强制

// 类模板中成员函数的类外实现
template<typename T1, typename T2>
class Person
{
public:
    // 类内声明，类外实现
    Person(T1 name, T2 age);

    // 类内声明，类外实现
    void showPerson();

    T1 m_Name;
    T2 m_Age;
};

template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    m_Name = name;
    m_Age = age;
}

template<typename T1, typename T2>
void Person<T1, T2>::showPerson()
{
    cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
}
