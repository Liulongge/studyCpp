#include <iostream>
#include <string>
using namespace std;

// 重载运算法
// 运算符重载概念：对已有的运算符重新进行定义，赋予其另外一种功能，以适应不同数据类型

// 对于内置的数据类型，编译器知道如何进行运算
// int a = 10;
// int b = 10;
// int c = a + b;

// ###### 关系运算符重载 ######
// 作用：重载关系运算符，可以让两个自定义类型对象进行对比操作


class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    // 重载关系关系运算符
    // 重载等于号 ==
    bool operator==(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // 重载不等号 !=
    bool operator!=(Person &p)
    {
        if(this->m_Name != p.m_Name || this->m_Age != p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};


void test01()
{
    Person p1("Tom", 18);
    Person p2("Tom", 20);

    if(p1 == p2)
    {
        cout << "p1 和 p2 是相等的" << endl;
    }
    else
    {
        cout << "p1 和 p2 是不相等的" << endl;
    }

    if(p1 != p2)
    {
        cout << "p1 和 p2 是不相等的" << endl;
    }
    else
    {
        cout << "p1 和 p2 是相等的" << endl;
    }
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}