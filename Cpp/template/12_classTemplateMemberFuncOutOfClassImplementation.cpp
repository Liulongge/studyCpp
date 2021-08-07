#include<iostream>
#include<string>
using namespace std;

// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// 总结：类模板中成员函数类外实现，需要加上模板参数列表

// 类模板中成员函数的类外实现
template<typename T1, typename T2>
class Person
{
public:
    // 类内声明，类外实现
    Person(T1 name, T2 age);
    // Person(T1 name, T2 age)
    // {
    //     m_Name = name;
    //     m_Age = age;
    // }

    // 类内声明，类外实现
    void showPerson();
    // void shoePerson()
    // {
    //     cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
    // }

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

void test01()
{
    Person<string, int> p1("Tom", 20);
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}