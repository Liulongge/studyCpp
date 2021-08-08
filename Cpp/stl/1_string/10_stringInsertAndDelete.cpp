#include<iostream>
#include<string>

using namespace std;

// string 基本概念
// 本质：
// string 是C++风格字符串，而string本质是一个类

// string 插入和删除
// 功能描述：对string 字符串进行 插入 和 删除 字符操作

// 函数原型
// string& insert(int pos, const char* s);      插入字符串
// string& insert(int pos, const string& str);  插入字符串
// string& insert(int pos, int n, char c);      在指定位置插入 n 个字符 c
// string& erase(int pos, int n = npos);        删除从 pos 开始的 n 个字符

// 总结：插入和删除的起始下标都是从 0 开始的

void test01()
{
    string str = "hello";
    // 插入
    str.insert(1, "111");
    cout << str << endl;

    // 擦除, 从1 号位置开始3个字符
    str.erase(1, 3);
    cout << str << endl;
}

int main()
{
    test01();
    return 0;
}