#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// string 基本概念
// 本质：
// string 是C++风格字符串，而string本质是一个类

// string 赋值操作
// 功能描述：
// 给 string 字符串进行赋值

// 赋值的函数原型
// string& operator=(const char* s);       char* 类型字符串 赋值给当前的字符串
// string& operator=(const char* &);       把字符串 s 赋值给当前的字符串
// string& operator=(const char c);        把字符赋值给当前的字符串
// string& assign(const char *s);          把字符串 s 赋值给当前的字符串
// string& assign(const char *s, int n);   把字符串 s 的前 n 个字符赋值给当前的字符串
// string& assign(const char &s);          把字符串 s 赋值给当前字符串      
// string& assign(int n, char c);          用 n 个字符 c 赋值给当前字符串

// 总结：string 的赋值方法有很多， operator= 这种方式是比较使用的

void test01()
{
    string str1;
    str1 = "Hello World!";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("Hello Cpp");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("Hello Cpp", 5);
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(6, '6');
    cout << "str7 = " << str7 << endl;
}

int main()
{
    test01();
    return 0;
}