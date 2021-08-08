#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// string 基本概念
// 本质：
// string 是C++风格字符串，而string本质是一个类

// string 字符串拼接
// 功能描述：
// 实现在字符串末尾拼接字符串

// 函数原型：
// string& operator+=(const char* str);             重载 += 操作符
// string& operator+=(const char c);                重载 += 操作符
// string& operator+=(const string &str);           重载 += 操作符
// string& append(const char *s);                   把字符串 s 链接到当前字符串结尾
// string& append(const char *s, int n);            把字符串 s 的前 n 个字符连接到当前字符串结尾
// string& append(const string &s);                 operator+=(const string &str)    
// string& append(const string &s, int pos, int n); 字符串 s 中从 pos 开始的第 n 个字符连接到字符串结尾

// 总结：

void test01()
{
    string str1 = "Hello ";
    str1 += "World ";
    cout << "str1 = " << str1 << endl;

    str1 += '!';
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = " Hello Cpp";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3;
    str3 = "Hello ";
    str3.append("World !");
    cout << "str3 = " << str3 << endl;

    str3.append(" Hello Cpp", 6);
    cout << "str3 = " << str3 << endl;

    str3.append(" Cpp");
    cout << "str3 = " << str3 << endl;

    string str4;
    str4 = "Hello ";
    string str5;
    str5 = "Hello World !";
    str4.append(str5, 6, 7);
    cout << "str4 = " << str4 << endl;
}

int main()
{
    test01();
    return 0;
}