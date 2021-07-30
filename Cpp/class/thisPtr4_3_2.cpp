
#include <iostream>
#include <string>
using namespace std;

// this指针概念
// C++中类的成员变量和成员函数是分开存储的
// 每一个静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
// 那么问题是：这块代码是如何区分那个对象调用自己的呢？

// C++通过提供特殊的对象指针，this指针，解决上述问题
// !!! this指针指向被调用的成员函数所属的对象 !!!

// this指针是隐含每一个非静态成员函数内的一种指针
// this指针不需要定义，直接使用即可

// this指针的用途
// 当形参和成员变量同名时，可以用this指针来区分
// 在类的非静态成员函数中返回对象本身，可使用return *this

// 作用：
// 1.解决名称冲突
// 2.返回对象本身

class Person
{
public:
    // 认为三个 age 是一回事，和 属性age 不是一回事
    // Person(int age)
    // {
    //     age = age;
    // }

    // 加上 this 解决
    // this 指针指向的是被调用成员函数所属的对象(p1), 成员函数属于 p1 即：this 指向的是 p1
    Person(int age)
    {
        this->age = age;
    }

    void PersonAddAge(Person &p)
    {
        // 自身 age += p.age
        this->age += p.age;
    }

    //用引用的方式返回代码本体
    Person& PersonAddAgeMuti(Person &p)
    {
        // 自身 age += p.age
        this->age += p.age;
        // this 指向p2的指针，而*this指向的就是p2这个对象的本体
        return *this;
    }
    int age;
};

void test01()
{
    Person p1(18);
    cout << "p1 的年龄为: " << p1.age << endl;
}

// 返回对象本身用 *this
void test02()
{
    Person p1(10);
    Person p2(10);
    p2.PersonAddAge(p1);
    cout << "p2 的年龄为: " << p2.age << endl;

    // *this 返回对象本身
    // 链式编程思想，cout就是链式编程思想，可以无限制追加
    p2.PersonAddAgeMuti(p1).PersonAddAgeMuti(p1).PersonAddAgeMuti(p1);
    cout << "p2 的年龄为: " << p2.age << endl;
}

int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}
