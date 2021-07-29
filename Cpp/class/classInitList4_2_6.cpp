#include <iostream>
#include <string>
using namespace std;

// 初始化列表

// C++ 提供了初始化列表，用来初始化属性
// 语法：构造函数（）：属性1（值1），属性2（值2），...{}

class Persion
{
public:

    // 传统初始化
    // Persion(int a, int b, int c)
    // {
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    // 列表初始化 1
    Persion():m_A(10),m_B(20),m_C(30)
    {

    }

    // 初始化列表初始化属性 2
    Persion(int a, int b, int c):m_A(a),m_B(b),m_C(c)
    {

    }

    Persion():m_A(10),m_B(20),m_C(30)
    {

    }
    int m_A;
    int m_B;
    int m_C;

};

void test01()
{
    // 传统初始化
    // Persion p(10, 20, 30);
    // 列表初始化 1
    // Persion p(10,20,30);
    // 列表初始化 2
    Persion p;
    cout << "m_A = " << p.m_A << endl;
    cout << "m_B = " << p.m_B << endl;
    cout << "m_C = " << p.m_C << endl;
}
int main(int argc, char *argv[])
{
    test01();

    // P.m_Name 不可读写， 私有属性
    return 0;
}