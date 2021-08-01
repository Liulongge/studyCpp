#include <iostream>
#include <string>

using namespace std;

// C++允许一个类继承多个类
// 语法：class 子类 : 继承方式 父类, 继承方式 : 父类 ...
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分

// C++实际开发中不建议用多继承

// 二义性
// 当父类中出现同名成员，需要加作用域区分
class Base1
{
public:
    Base1()
    {
        m_A = 100;
    }
    int m_A;
};

class Base2
{
public:
    Base2()
    {
        m_A = 200;
    }
    int m_A;
};

// 子类 需要继承Base1 Base2 
// 语法：class 子类 : 继承方式 父类, 继承方式 : 父类 ...
class Son : public Base1, public Base2
{
public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

void test01()
{
    Son s;
    // sizeof Son: 16
    cout << "sizeof Son: " << sizeof(Son) << endl;

    // 二义性
    // 当父类中出现同名成员，需要加作用域区分
    cout << "s.Base1::m_A = " << s.Base1::m_A << endl;  
    cout << "s.Base2::m_A = " << s.Base2::m_A << endl;    
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}