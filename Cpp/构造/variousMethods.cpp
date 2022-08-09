#include <iostream>
#include <string>
using namespace std;

// 构造函数的分类和调用
// 两种分类方式
    // 按参数分类: 有参数构造，无参数构造
    // 按类型分类: 普通构造，拷贝构造
// 三种调用方式
    // 括号法
    // 显示法
    // 隐式转换法

// 分类
class Persion
{
public:
    // 无参构造函数（默认构造函数）
    Persion()
    {
        cout << "Persion 的无参（默认）构造函数" << endl;
    }
    // 有参构造函数
    Persion(int a)
    {
        age = a;
        cout << "Persion 的有参构造函数" << endl;
    }
    // 拷贝构造函数，将p的属性赋值一份，构造一模一样的对象
    // 传进来的变量不能够被改变，加const
    // 采用引用方式
    Persion(const Persion &p)
    {
        // 将传入的人身上的属性，拷贝到我身上
        age = p.age;
        cout << "Persion 的拷贝构造函数" << endl;
    }
    ~Persion()
    {
        cout << "Persion 的析构函数" << endl;
    }
    int age;
};


void test01()
{
    cout << "--------------------" << endl;
    Persion P0;     // 默认构造函数调用
    
    // 1.括号法
    // 注意：调用默认构造函数的时候，不要加()，否则编译器会认为是函数的声明，不认为是在创建对象。
    Persion P1(10); // 有参构造函数调用
    cout << "P1的年龄：" << P1.age << endl;
    Persion P2(P1); // 拷贝构造
    cout << "P2的年龄：" << P2.age << endl;
    // Persion P3();   // 这行代码会被编译器认为是函数的声明，像 void P3();
    
    // 2.显示法
    cout << "--------------------" << endl;
    Persion P4;
    Persion P5 = Persion(20);  // 有参构造
    Persion P6 = Persion(P5);  // 拷贝构造
    Persion(10);               // 匿名对象，当前行执行结束后，系统会立即回收掉匿名对象。
    cout << "匿名对象会立马被析构掉" << endl;
    // 注意事项：不要利用拷贝构造函数，初始化匿名对象，编译器会认为Persion(P3) 等价于 Persion P3;
    // Persion(P6);

    // 3.隐式法
    cout << "--------------------" << endl;
    Persion P7 = 10; // 等价于 Persion P6 = Persion(10);
    Persion P8 = P7; // 拷贝构造
    
    cout << "--------------------" << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}