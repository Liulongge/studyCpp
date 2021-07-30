
#include <iostream>
#include <string>
using namespace std;

// c++对象模型和this指针

// 成员变量和成员函数分开存储
// 在C++中，类的成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上

class Person
{

};

class Person2
{
    // 非静态成员变量属于类的对象
    int m_A;
    // 类的静态成员变量，类内声明，类外初始化
    static int m_B;
};

// 静态成员变量类外初始化
int Person2::m_B = 0;

class Person3
{
    // 非静态成员变量属于类的对象
    int m_A;
    // 类的静态成员变量，类内声明，类外初始化
    static int m_B;

    // 类的非静态成员函数，不适于类的对象上
    void func()
    {

    }

    // 静态成员函数，不属于类的对象上
    static void func2()
    {

    } 
};

// 总结 只有类的非静态成员函数属于类的对象上
void test01()
{
    // 空对象占用内存空间 1 字节
    // C++编译器会给每个空对象一个字节的空间，为了区分空对象占据内存的未知，两个空对象，可以区分开来
    // 每个空对象也应该有一个独一无二的内存地址
    cout << sizeof(Person) << endl;

    // 对象占用 4 字节
    // 类的静态成员变量不属于某一个对象，不属于类对象上
    cout << sizeof(Person2) << endl;

    // 对象占用 4 字节
    cout << sizeof(Person3) << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}
