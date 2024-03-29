#include <iostream>
#include <string>

using namespace std;

// 继承是面向对象三大特征之一
// 有些类与类之间存在特殊的关系
// 我们发现定义这些类时，下级别的成员拥有上一级的共性，还有自己的特性
// 这时候我们就可以考虑利用继承技术，减少重复代码

// 继承的基本语法：
// 例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中间内容不同
// 接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承的意义和好处

// 继承的好处：
// 减少重复的代码

// 语法：
// class 子类 ： 继承方式 父类
// 别称：
// 子类： 派生类
// 父类： 基类

// 派生类中的成员，包含两大部分
// 一类是基类继承过来的，一类是自己添加的成员
// 从基类继承过来的表现其共性，而新增的成员体现了其个性

// 继承的方式有三种：
// 1.公共继承
// 2.保护继承
// 3.私有继承

// 子类继承父类后，当创建子类对象，也会调用父类的构造函数
// 问题：
// 父类和子类的构造和析构顺序是谁先谁后?
// 继承中的构造和析构中的顺序如下：
// 先构造父类，再构造子类，析构的顺序与构造的顺序相反

class Base
{
public:
    Base()
    {
        cout << "Base 的构造函数被调用" << endl;
    }
    ~Base()
    {
        cout << "Base 的析构函数被调用" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son 的构造函数被调用" << endl;
    }
    ~Son()
    {
        cout << "Son 的析构函数被调用" << endl;
    }
};

void test01()
{
    // 创建子类对象，由于继承，也会创建父类对象
    // Base 的构造函数被调用
    // Son 的构造函数被调用
    // Son 的析构函数被调用
    // Base 的析构函数被调用
   Son son;
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}