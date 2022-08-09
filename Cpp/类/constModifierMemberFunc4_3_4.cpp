
#include <iostream>
#include <string>
using namespace std;

// const修饰成员函数

// 常函数：
// 成员函数后加 const 后称为这个函数为常函数
// 成员属性声明时加关键词 mutable 后，在常函数中依然可以修改

// 常对象：
// 声明对象前加 const 称该对象为常对象
// 常对象只能调用常函数

class Person
{
public:
    // this 指针的本质 是指针常量  指针的指向是不可修改的
    // Person * const this, this 指针不可以修改
    // const Person * const this, this 指针指向的值不可以修改
    // 在成员函数后面加 const，修饰的是this指向，让指针指向的值也不可以修改
    void showPerson() const  // 相当于 const Person * const this, this 指针的指向 和 指针指向的值 都不可以修改
    {
        //this->m_A = 10;
        // this = nullptr; // this 指针是不可以修改指针的指向，指针常量

        this->m_B = 10;  // 可以修改 mutalbe 修饰的成员函数
    }

    void func()
    {
        m_B = 10;
    }

    int m_A = 0;
    mutable int m_B = 0; // 特殊变量，即使在常函数中，也可以修改这个值，加上关键字 mutable
};

// 常函数
void test01()
{
    Person p;
    p.showPerson();
}

// 常对象
void test02()
{
    const Person p; // 在对象前加const, 变为常对象，指向的值不能被修改
    // p.m_A = 1000;
    p.m_B = 10;

    p.showPerson();
    // 常对象只能调用常函数！！！
    //p.func(); // 常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
}
int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}
