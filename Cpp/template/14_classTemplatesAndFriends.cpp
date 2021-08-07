#include<iostream>
#include<string>
using namespace std;

// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// 类模板与友元
// 掌握类模板配合友元函数的 类内 和 类外 实现

// 全局函数类内实现 - 直接在类内声明，类外实现即可
// 全局函数类外实现 - 需要提前让编译器知道 全局函数 的存在

// 建议：如果没有特殊需求，全局函数做类内实现，用法简单，而且编译器可以直接识别

// 声明class，让编译器知道Person的存在
template<typename T1, typename T2>
class Person;

// 全局函数类外实现
// 函数模板的实现
template<typename T1, typename T2>
void printPerson2(Person<T1, T2> p)
{
    cout << "name: " << p.m_Name << ", age: " << p.m_Age << endl;
}

template<typename T1, typename T2>
class Person
{
    // 1.全局函数类内实现
    friend void printPerson(Person<T1, T2> p)
    {
        cout << "name: " << p.m_Name << ", age: " << p.m_Age << endl;
    }
    // 2.全集函数类外实现
    // 普通函数声明不行， 需要声明为 函数模板，加空模板参数列表
    // 如果全局函数 是 类外实现，需要让编译器提前知道这个函数的存在
    
    friend void printPerson2<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

void test01()
{
    Person<string, int> p("Tom", 100);
    printPerson(p);
    printPerson2(p);
}

int main()
{
    test01();
    return 0;
}