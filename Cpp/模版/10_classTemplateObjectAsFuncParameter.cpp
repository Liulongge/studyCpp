#include<iostream>
#include<string>
using namespace std;

// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// 类模板实例化出的对象，向函数传递的方式

// 一共三种传入方式：
// 指定传入的类型  -- 直接显示对象的数据类型
// 参数模板化     -- 将对象中的参数变为模板进行传递
// 整个类模板化    -- 将这个对象类型 模板化进行传递

// 总结：
// 通过类模板创建的对象，可以有三种方式向函数中进行传参
// 使用比较广泛的是第一种：指定传入类型

template<typename T1, typename T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    void showPerson()
    {
        cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
    }
    T1 m_Name;
    T2 m_Age;
};

// 1.指定传入类型
void printPerson1(Person<string, int> &p)
{
    p.showPerson();
}

// 2.将参数模板化
template<typename T1, typename T2>
void printPerson2(Person<T1, T2> &p)
{
    p.showPerson();
    cout << "T1 的类型为： " << typeid(T1).name() << endl;
    cout << "T2 的类型为： " << typeid(T2).name() << endl;
}

// 3.将整个类模板化
template<typename T>
void printPerson3(T &p)
{
    p.showPerson();
    cout << "T 的类型为： " << typeid(T).name() << endl;
}

void test01()
{
    // 1.指定传入的类型
    Person<string, int> p1("Tom", 100);
    printPerson1(p1);

    // 2.将参数模板化
    Person<string, int> p2("Cook", 100);
    printPerson2(p2);
    
    // 3.将整个类模板化
    Person<string, int> p3("Tim", 30);
    printPerson3(p3);
}

int main()
{
    test01();
    return 0;
}