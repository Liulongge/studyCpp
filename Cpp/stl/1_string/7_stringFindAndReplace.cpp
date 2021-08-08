#include<iostream>
#include<string>

using namespace std;

// string 基本概念
// 本质：
// string 是C++风格字符串，而string本质是一个类

// 字符串查找和替换
// 查找：查找指定字符串是否存在
// 替换：在指定的位置替换字符串

// 函数原型
// int find(const string &str, int pos = 0) const;         查找 str 第一次出现位置，从 pos 开始查找
// int find(const char* s, int pos = 0) const;             查找 s 第一次出现位置，从 pos 开始查找
// int find(const char* s, int pos, int n) const;          从 pos 位置查找 s 的前 n 个字符串第一个位置
// int find(const char c, int pos = 0) const;              查找字符 c 第一次出现的位置
// int rfind(const string &str, int pos = npos) const;     查找 str 最后一次出现的位置，从 pos 开始查找
// int rfind(const char* s, int pos = npos) const;         查找 s 最后一次出现的位置，从 pos 开始查找
// int rfind(const char* s, int pos, int n) const;         从 pos 查找 s 的前 n 个字符最后一次位置
// int rfind(const char c, int pos = 0) const;             查找字符 c 最后一次出现的位置
// string& replace(int pos, int n, const string& str);     替换从 pos 开始 n 个字符为字符串 str
// string& replace(int pos, int n, const char* s);         替换从 pos 开始的 n 个字符为字符串 s

// 总结：
// find 查找从左往右，rfind 查找从右往左
// find 找到字符串后返回找到的第一个字符位置，找不到返回 -1
// replace 在替换时，要指定从哪一个位置起，多少个字符，替换成什么样的字符串

void test01()
{
    string str1 = "abcdefde";
    // 如果没有，返回 -1
    int pos = str1.find("de");
    if(pos == -1)
    {
        cout << "未找到字符串" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }

    // rfind 与 find 区别
    // rfind 从右往左查找
    // find 从左往右查找
    pos = str1.rfind("de");
    if(pos == -1)
    {
        cout << "未找到字符串" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }
}

void test02()
{
    string str1 = "abcdefg";
    // 从 1 号位置起 3个字符 替换为 111111
    str1.replace(1, 3, "111111");
    cout << "str1 = " << str1 << endl;

}
int main()
{
    // 查找
    test01();
    // 替换
    test02();
    return 0;
}