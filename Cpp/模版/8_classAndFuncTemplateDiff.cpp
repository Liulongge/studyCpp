#include<iostream>
#include<string>
using namespace std;

// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// 类模板和函数模板区别主要有两点
// 1.类模板没有自动类型推导的使用方式
// 2.类模板在模板参数列表中可以有默认参数，函数模板中没有

// 类模板
// 类模板在模板参数列表中可以有默认参数,typename AgeType = int
// 函数模板中没有 默认参数

template<typename NameType, typename AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    // 类模板没有自动类型推导的使用方式, 只能显示指定
    // Person p("Tom", 1000);
    Person<string, int> p("Tom", 1000);
    p.showPerson();
}

void test02()
{
    // 类模板在模板参数列表中可以有默认参数,template<typename NameType, typename AgeType = int>
    Person<string> p("Tim", 1000);
    p.showPerson();
}

int main()
{
    test01();
    test02();
    return 0;
}