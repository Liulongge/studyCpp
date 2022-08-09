#include <iostream>
#include <string>
using namespace std;

// 多态，多种形态
// 多态是C++面向对象三大特征之一
// 静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
// 动态重载：派生类 和 虚函数实现运行时多态

// 多态案例--计算器类
// 案例描述
// 分别利用普通写法和多态技术，实现两个操作数进行运算的计算器类

// 多态的优点
// 代码组织结构清晰
// 可读性强
// 利于前期和后期的扩展以及维护

// 1.普通实现
class Calculator
{
public:
    // 虚函数
    int getResult(string oper)
    {
        if(oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if(oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if(oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        else if(oper == "/")
        {
            return m_Num1 / m_Num2;
        }
        else
        {
            return -1;
        }
        // 如果想扩展新功能，需要修改源码
        // 在真实开发中，提倡 开闭原则
        // 开闭原则： 对扩展进行开放，对修改进行关闭
    }
    int m_Num1; // 操作数1
    int m_Num2; // 操作数2
};

// 2.多态实现
// 实现计算器的基类，抽象类
// 组织结构清晰
// 可读性强，子类重写父类中虚函数
// 对于前期和后期扩展及维护性高
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

// 加法计算器类
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {

        return m_Num1 + m_Num2;
    }
};

// 减法计算器类
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {

        return m_Num1 - m_Num2;
    }
};

// 乘法计算器类
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {

        return m_Num1 * m_Num2;
    }
};

void test01()
{
    cout << "###### 普通实现 ######" << endl;
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
    cout << c.m_Num1 << " / " << c.m_Num2 << " = " << c.getResult("/") << endl;
}

void test02()
{
    // 多态的使用条件
    // 父类的指针或者引用指向子类对象
    cout << "##### 多态实现 ######" << endl;
    // 加法运算
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;


    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;


}

int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}