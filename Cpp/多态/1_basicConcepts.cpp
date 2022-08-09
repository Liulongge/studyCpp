#include <iostream>
#include <string>
using namespace std;

// 多态，多种形态
// 多态是C++面向对象三大特征之一
// 静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
// 动态重载：派生类 和 虚函数实现运行时多态

// 静态多态和动态多态区别：
// 静态多态的函数地址早绑定 - 编译阶段确定函数地址
// 动态多态的函数地址晚绑定 - 运行阶段才确定函数地址

// 动态多态的满足条件
// 1.有继承关系
// 2.子类重写父类中的虚函数（函数名，形参列表，返回值类型完全相同）

// 多态的使用
// 父类的指针或者引用 指向子类的对象

class Animal
{
public:
    // 虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

// 地址早绑定，在编译阶段确定函数的地址
// 如果想执行让猫说话，这个函数的地址就不能早绑定，需要在运行阶段进行绑定，晚绑定
// 函数的地址不能提前确定下来

void doSpeak(Animal &animal) // Animal &animal = cat
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}