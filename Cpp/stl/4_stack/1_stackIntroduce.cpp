#include<iostream>
#include<stack>
#include<string>

using namespace std;

// stack 基本概念
// 概念：stack是一个 先进后出(First In Last Out, FILO) 的数据结构，他只有一个出口
// 栈中只有顶端的元素才可以被外界使用，因此栈不允许遍历行为
// 栈中进入数据称为 --- 入栈 push
// 栈中弹出数据称为 --- 出栈 pop

// 生活中的栈： 弹夹、挤地铁

// 函数原型：
// 1.构造函数
// stack<T> stk;               stack 采用模板类实现，stack对象的默认构造形式
// stack(const stack &stk);    拷贝构造函数

// 2.赋值操作
// stack& operator=(const stack &stk);  重载等号操作符

// 3.数据存取
// push(elem);     向栈顶添加元素    
// pop();          从栈顶移除第一个元素
// top()；         返回栈顶元素

// 4.大小操作
// empty();        判断栈是否为空
// size();         返回栈的大小

// 总结：
// 入栈           --- push
// 出栈           --- pop
// 返回栈顶        --- top
// 判断栈是否为空   --- empty
// 返回栈大小      ---  size

void test01()
{
    // 先进后出的数据结构
    stack<int> s;
    // 入栈 10 20 30 40
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "s.size() = " << s.size() << endl;

    // 只要栈不为空，我们就查看栈顶，并执行出栈操作
    while( !s.empty() )
    {
        // 查看栈顶元素
        // 40 30 20 10
        cout << s.top() << endl;
        s.pop();
    }
    cout << "s.size() = " << s.size() << endl;
}

int main()
{
    test01();
    return 0;
}