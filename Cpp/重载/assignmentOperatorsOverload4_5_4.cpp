#include <iostream>
#include <string>
using namespace std;

// 重载运算法
// 运算符重载概念：对已有的运算符重新进行定义，赋予其另外一种功能，以适应不同数据类型

// 对于内置的数据类型，编译器知道如何进行运算
// int a = 10;
// int b = 10;
// int c = a + b;

// ###### 赋值运算符重载 ######
// 作用：通过重载递增运算符，实现自己的整形数据

// C++编译器至少给一个类添加4个函数
// 1.默认构造函数（无参，函数体为空）
// 2.默认析构函数（无参，函数体为空）
// 3.默认拷贝构造函数，对属性进行值拷贝
// 4.赋值运算符 operator=，对属性进行值赋值

// 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题

class Person
{
public:
    Person(int age)
    {
        // 开辟堆区内存
        // 内存由程序员申请 并 释放
        m_Age = new int(age);
    }
    ~Person()
    {
        if(m_Age != nullptr)
        {
            delete m_Age;
        }
    }
    // 重载赋值运算符
    Person &operator=(Person &p)
    {
        // 编译器提供浅拷贝
        // 浅拷贝会造成堆区内存重复释放
        // m_Age = p.m_Age;

        // 应该先判断有属性在堆区，如果有 先释放干净 然后再深拷贝
        if(m_Age != nullptr)
        {
            delete m_Age;
            m_Age = nullptr;
        }
        // 深拷贝
        m_Age = new int(*p.m_Age);
        // 要返回对象本身
        return *this;
    }
    int *m_Age;
};

// 前置递增
void test01()
{
    Person p1(18);

    Person p2(20);

    cout << "p1 的年龄：" << *p1.m_Age << endl;
    cout << "p2 的年龄：" << *p2.m_Age << endl;

    // 赋值操作, 浅拷贝
    p2 = p1;

    Person p3(30);
    p3 = p2 = p1;
    cout << "p1 的年龄：" << *p1.m_Age << endl;
    cout << "p2 的年龄：" << *p2.m_Age << endl;
    cout << "p3 的年龄：" << *p3.m_Age << endl;
}
int main(int argc, char *argv[])
{
    test01();

    int a = 10;
    int b = 10;
    int c = a = b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    return 0;
}