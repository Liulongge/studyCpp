#include<iostream>
#include<string>
using namespace std;
// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// C++另一种编程思想就是 泛型编程 ，主要利用的技术的 模板
// C++提供两种模板机制：1.函数模板、2.类模板

// 注意事项
// 自动推类型推导，必须推导出一致的数据类型 T 才可以使用
// 摸版必须要确定出 T 的数据类型，才可以使用

// 模板虽然通用，但不是万能的
// 例如：
// template<typename T>
// void f(T a, T b)
// {
//     a = b;
//     if(a > b)
//     {
//         ...
//     }
// }
// 若 T 为数组，就不再成立
// 若 T 为Person数据类型，也无法正常运行

// 因此C++为了解决这种问题，提供模板的重载，可以为这些特定的数据类型提供具体的模板 ！！！

// 总结：
// 1.利用具体化模板，可以解决自定义类型的通用化
// 2.学习模板并不是为了写模板，而是在 STL 中运用系统提供的模板

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

// 对比两个数据是否相等的函数
template<typename T>
bool myCompare(T &a, T &b)
{
    if(a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 利用具体化Person版本实现代码，具体化优先调用
template<> bool myCompare(Person &a, Person &b)
{
    if((a.m_Name == b.m_Name) && (a.m_Age == b.m_Age))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    float a = 10.0;
    float b = 20.0;
    
    bool ret = myCompare(a, b);
    if(ret)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }
}

void test02()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    bool ret = myCompare(p1, p2);

    if(ret)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}