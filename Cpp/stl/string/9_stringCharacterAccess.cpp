#include<iostream>
#include<string>

using namespace std;

// string 基本概念
// 本质：
// string 是C++风格字符串，而string本质是一个类

// string 中单个字符存取方式有两种：
// 1. char& operator[](int n)
// 2. char& at(int n)

void test01()
{
    string str = "hello world !";
    // 通过中括号访问字符
    for(int i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }
    cout << endl;

    // 通过 at 方式，访问字符中单个字符
    for(int i = 0; i < str.size(); i++)
    {
        cout << str.at(i);
    }
    cout << endl;

    // 修改单个字符
    str[0] = 'x';
    cout << str << endl;

    str.at(1) = 'x';
    cout << str << endl;
}

int main()
{
    test01();
    return 0;
}