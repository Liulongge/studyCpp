#include <iostream>
#include <string>
using namespace std;

// 多态，多种形态
// 多态是C++面向对象三大特征之一
// 静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
// 动态重载：派生类 和 虚函数实现运行时多态

// 案例描述
// 制作饮品的大致流程：煮水 - 冲泡 - 倒入杯子里 - 加入辅料
// 利用多态技术实现案例，提供抽象制作饮品的基类，提供子类制作咖啡和茶叶

// 纯虚函数，抽象基类，
class AbstractDrinking
{
public:
    // 煮水
    virtual void Boil() = 0;
    // 冲泡
    virtual void Brew() = 0;
    // 倒入杯中
    virtual void PourInCup() = 0;
    // 加入辅料
    virtual void PutSomething() = 0;

    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Coffe : public AbstractDrinking
{
public:
    // 煮水
    virtual void Boil()
    {
        cout << " 煮农夫山泉 " << endl;
    }
    // 冲泡
    virtual void Brew()
    {
        cout << " 冲泡咖啡 " << endl;
    }
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << " 倒入杯中 " << endl;
    }
    // 加入辅料
    virtual void PutSomething()
    {
        cout << " 加入辅料 " << endl;
    }
};

class Tea : public AbstractDrinking
{
public:
    // 煮水
    virtual void Boil()
    {
        cout << " 煮矿泉水 " << endl;
    }
    // 冲泡
    virtual void Brew()
    {
        cout << " 冲泡绿茶 " << endl;
    }
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << " 倒入杯中 " << endl;
    }
    // 加入辅料
    virtual void PutSomething()
    {
        cout << " 加入枸杞 " << endl;
    }
};

void doWork(AbstractDrinking *abs)
{
    abs->makeDrink();
    delete abs;
}

void test01()
{
    // 制作咖啡
    cout << "====== 制作咖啡 ======" << endl;
    doWork(new Coffe);

    // 制作绿茶
    cout << "====== 制作绿茶 ======" << endl;
    doWork(new Tea);
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}