#include <iostream>
#include <string>
using namespace std;

// 构造函数调用规则

// 默认情况下C++编译器至少给一个类添加3个函数
// 1.默认构造函数（无参，函数体为空）
// 2.默认析构函数（无参，函数体为空）
// 3.默认拷贝构造函数，对属性值进行拷贝

// 重点：！！！
// 构造函数调用规则如下：
// 如果用户定于有参构造函数，C++不再提供默认无参构造函数，但是会提供默认拷贝函数
// 如果用户定义拷贝函数，C++不再提供其他构造函数

// 默认构造 -> 有参构造 -> 拷贝构造
// 用户提供xxx构造函数之后，编译器将不再提供其之前的 xxx构造函数。

class Persion
{
public:
    Persion()
    {
        cout<< "Persion 的默认构造函数 " << endl;
    }
    Persion(int age)
    {
        cout<< "Persion 的有参构造函数 " << endl;
        m_Age = age;
    }
    // 即使没有拷贝构造函数，编译器也会默认加入！！！
    // Persion(const Persion &p)
    // {
    //     cout<< "Persion 拷贝参构造函数 " << endl;
    //     m_Age = p.m_Age;
    // }
    ~Persion()
    {
        cout<< "Persion 的析构造函数 " << endl;
    }
    int m_Age;
};

void test01()
{
    Persion p;
    p.m_Age = 18;

    Persion p2(p);

    cout << "p2 的年龄：" << p2.m_Age << endl;
}

void test02()
{
    // 如果用户提供了有参构造函数，系统将不会提供默认构造函数
    // 把默认构造函数注释掉，编译将报错。
    // Persion p; // constructorCallRule4_2_4.cpp:45:13: error: no matching constructor for initialization of 'Persion'
    Persion p2(10);
    cout << "p2 的年龄：" << p2.m_Age << endl;
}
int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}