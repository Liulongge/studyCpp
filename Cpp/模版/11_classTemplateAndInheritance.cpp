#include<iostream>
#include<string>
using namespace std;

// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// 当类模板碰到继承时，需要注意以下几点
// 当子类继承的父类是一个模板类时，子类在声明的时候，需要指定出父类中的 T 类型
// 如果不指定，编译器无法给予类分配内存
// 如果想灵活指定父类中 T 的类型，子类也需要变为类模板

// 总结： 如果父类是类模板，子类需要指定出父类中 T 的数据类型

template<typename T>
class Base
{
    T m;
};

// 必须要知道 父类中 T 的数据类型，才能继承给子类
// class Son : public Base
class Son1 : public Base<int>
{

};

// 如果想灵活指定父类中 T 的类型，子类也需要变为类模板
// T2 指定父类中 T 什么数据类型
template<typename T1, typename T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout << "T1 的数据类型：" << typeid(T1).name() << endl;
        cout << "T2 的数据类型：" << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test01()
{
    Son1 s1;

    Son2<int, char> s2;
}

int main()
{
    test01();
    return 0;
}