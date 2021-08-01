#include <iostream>
#include <string>
using namespace std;

// 重载运算法
// 运算符重载概念：对已有的运算符重新进行定义，赋予其另外一种功能，以适应不同数据类型

// 加法运算符重载
// 作用：实现两个自定义数据类型相加的运算

// 对于内置的数据类型，编译器知道如何进行运算
// int a = 10;
// int b = 10;
// int c = a + b;

// ###### 加号运算符重载 ######

// 1.成员函数实现 + 号运算符重载
// 2.全局函数重载 + 号

class Person
{
public:
    // 1.成员函数实现 + 号运算符重载
    // Person operator+(const Person& p)
    // {
    //     Person temp;
    //     temp.m_A = this->m_A + this->m_A;
    //     temp.m_B = this->m_B + this->m_B;
    //     return temp;
    // }
    int m_A;
    int m_B;
};

// 2.全局函数重载 + 号
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 运算符重载 也可以发生函数重载
// 函数重载版本
Person operator+(Person &p1, int num)
{
    Person temp;
    temp.m_A = p1.m_A + num;
    temp.m_B = p1.m_B + num;
    return temp;
}

void test01()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;

    // 1.成员函数重载的本质调用
    // Person p3 = p1.operator+(p2);
    // 2.全局函数重载的本质
    // Person p3 = operator+(p1, p2);
    Person p3 = p1 + p2;
    cout << "p3.m_A = " << p3.m_A << " , p3.m_B = " << p3.m_B << endl;

    // 运算符重载 也可以发生函数重载
    Person p4 = p1 + 20;
    cout << "p4.m_A = " << p4.m_A << " , p4.m_B = " << p4.m_B << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}