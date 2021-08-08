#include<iostream>
#include<string>

using namespace std;

// string 基本概念
// 本质：
// string 是C++风格字符串，而string本质是一个类

// string 字符串比较
// 功能描述
// 字符串之间的比较
// 比较方式
// 字符串比较是按照字符的 ASCII 码进行对比
// = 返回 0
// > 返回 1
// < 返回 -1

// 函数原型
// int compare(const string& s) const;  与字符串 s 比较
// int compare(const char* s) const;    与字符串 s 比较

// 总结：字符串对比主要用于比较两个字符串是否相等，判断谁大谁小的意义并不大
void test01()
{
    string str1 = "hello";
    string str2 = "hello";

    int result = str1.compare(str2) == 0;
    if(result)
    {
        cout << "str1 == str2" << endl;
    }
    else if(result == 1)
    {
        cout << "str1 < str2" << endl;
    }
    else
    {
        cout << "str1 > str2" << endl;
    }

    // 利用重载
    if(str1 == str2)
    {
        cout << "str1 == str2" << endl;
    }
}

int main()
{
    test01();
    return 0;
}