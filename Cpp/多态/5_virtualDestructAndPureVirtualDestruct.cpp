#include <iostream>
#include <string>
using namespace std;

// 多态，多种形态
// 多态是C++面向对象三大特征之一
// 静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
// 动态重载：派生类 和 虚函数实现运行时多态

// 多态的使用中，如果子类中有属性开辟在堆区，那么父类指针在释放时无法调用子类的析构代码
// 解决方式：将父类中的析构函数改为 虚析构 或者 纯虚构

// 虚析构和纯虚析构共性：
// 1.可以解决父类指针释放子类对象
// 2.都需要具体的函数实现

// 虚析构与纯析构区别：
// 1.如果是纯析构，该类属于抽象类，无法实例化对象

// 虚析构语法:
// virtual ~类名(){}
// 纯虚析构语法:
// virtual ~类名() = 0;

// 析构顺序 和 构造顺序相反，先构造父类
// Animal 的构造函数
// Cat 的析构函数
// Tom小猫在说话
// Cat 的析构函数
// Animal 的析构函数

// 总结
// 1.虚析构或者纯虚析构就是用来解决通过父类指针释放子类对象
// 2.如果子类中没有堆区数据，可以不写为虚构或者纯虚构
// 3.拥有纯虚析构函数的类也属于抽象类

class Animal
{
public:
    Animal()
    {
        cout << "Animal 的构造函数" << endl;
    }
    // 虚析构
    // 把析构改成虚析构，利用虚析构可以解决 父类指针释放子类对象是不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal 的虚析构函数" << endl;
    // }

    // 纯虚析构，也需要代码的实现
    // 有了纯虚析构之后，这个类也是抽象类，无法实例化对象
    virtual ~Animal() = 0;
    // 纯虚函数
    virtual void speak()  = 0;
};

// Animal下面的纯虚析构，有可能父类中也有一些 堆区内存 需要释放
Animal::~Animal()
{
    cout << "Animal 的纯虚构造函数" << endl;
}
class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat 的析构函数" << endl;
        m_Name = new string(name);
    }
    void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    }
    ~Cat()
    {
        if(m_Name != nullptr)
        {
            cout << "Cat 的析构函数" << endl;
            delete m_Name;
            m_Name = nullptr;
        } 
    }
    string *m_Name;
};

void test01()
{
    Animal * animal = new Cat("Tom");
    animal->speak();
    // 父类的指针在虚构之后不会调用子类中析构函数，导致子类如果有堆区属性，会造成内存泄漏
    delete animal;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}