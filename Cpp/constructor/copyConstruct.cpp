#include <iostream>
#include <string>
using namespace std;

// 拷贝构造函数调用时机

// 拷贝构造函数调用时机通常有三种情况：
// 1.使用一个已经创建完毕的对象来初始化一个对象
// 2.值传递的方式给函数参数传值
// 3.以值方式返回局部对象

class Persion
{
public:
    // 无参构造函数（默认构造函数）
    Persion()
    {
        cout << "Persion 的无参（默认）构造函数" << endl;
    }
    // 有参构造函数
    Persion(int age)
    {
        m_Age = age;
        cout << "Persion 的有参构造函数" << endl;
    }
    // 拷贝构造函数，将p的属性赋值一份，构造一模一样的对象
    // 传进来的变量不能够被改变，加const
    // 采用引用方式
    Persion(const Persion &p)
    {
        // 将传入的人身上的属性，拷贝到我身上
        m_Age = p.m_Age;
        cout << "Persion 的拷贝构造函数" << endl;
    }
    ~Persion()
    {
        cout << "Persion 的析构函数" << endl;
    }
    int m_Age;
};

// 1、使用已经创建完毕的对象来初始化一个新对象
void test01()
{
    Persion p1(20);
    Persion p2(p1);
    cout << "p2的年龄为：" << p2.m_Age << endl;
}

// 2、值传递的方式给函数参数传值
void doWork(Persion p)  // 值传递，拷贝构造
{

}
void test02()
{
    Persion p;
    doWork(p);
}

// 3、值方式返回局部对象
Persion doWork2()
{
    Persion p5;
    return p5;
}
void test03()
{
    Persion p4 = doWork2();
}

int main(int argc, char *argv[])
{
    test01();
    test02();
    test03();  // 编译器做了优化，没有发生拷贝构造。
    return 0;
}