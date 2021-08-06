#include<iostream>
#include<string>
using namespace std;
// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// 类模板作用
// 建立一个通用类，类中的成员 数据类型可以不具体制定，用一个 虚拟的类型 来表述

// 语法：
// template<typename T>
// 类

// 解释：
// template  --  声明创建模板
// typename -- 表明其后面的符号是一种数据类型，可以用 class 代替
// T  --  通用的数据类型，名称可以替换，通常为大写字母

// 总结：类模板 和 函数模板 语法相似，在声明模板 template 后面加类，此类称为 类模板

// 类模板
// 需要多个 T 来表述 name 与 age 数据类型
template<typename NameType, typename AgeType>
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
    // 将类型参数化
    Person<string, int> p1("Tom", 20);
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}