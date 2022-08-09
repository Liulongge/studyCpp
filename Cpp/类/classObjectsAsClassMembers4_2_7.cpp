#include <iostream>
#include <string>
using namespace std;

// 类对象作为类成员
// C++ 类中的成员可以是另一个类的对象，我们称该成员为对象成员

// 先走了人的构造，先有了手机的构造?
// 1. Phone 的构造函数调用
// 2. Person 的构造函数调用

// 当其他类对象作为本类成员，构造时候先构造自身

// 1. Person 的析构函数调用
// 2. Phone 的析构函数调用
// 析构函数，与构造函数相反
// 先析构自身，后析构调用

class Phone
{
public:
    Phone(string pName)
    {
        m_PName = pName;
        cout << "Phone 的构造函数调用" << endl;
    }
    ~Phone()
    {
        cout << "Phone 的析构函数调用" << endl;
    }
    // 手机品牌名称
    string m_PName;

};
class Person
{
public:
    // Phone m_Phone = pName 隐式转换法
    // 初始化列表
    Person(string name, string pName):m_Name(name),m_Phone(pName)
    {
        cout << "Person 的构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person 的析构函数调用" << endl;
    }
    // 姓名
    string m_Name;
    // 手机
    Phone m_Phone;
    int m_A;
    int m_B;
    int m_C;

};

void test01()
{
    Person p("张三","HUAWEI");
    cout << p.m_Name << endl;
    cout << p.m_Phone.m_PName << endl;
}
int main(int argc, char *argv[])
{
    test01();

    // P.m_Name 不可读写， 私有属性
    return 0;
}