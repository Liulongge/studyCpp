#include<iostream>
#include<string>

using namespace std;

// string 基本概念
// 本质：
// string 是C++风格字符串，而string本质是一个类

// 从字符串中获取想要的子串

// 函数原型
// string substr(int pos, int n = npos) const;

// 总结：灵活运用求子串的功能，可以在实际开发中获取有效的信息

void test01()
{
    string str = "abcdef";
    string substr = str.substr(1, 3);
    cout << "substr = " << substr << endl;

    // 实用操作
    string email = "zhangsan@sina.com";
    // 从邮件地址中获取 用户名信息
    int pos = email.find("@");
    string username = email.substr(0, pos);
    cout << "username = " << username << endl;

}

int main()
{
    test01();
    return 0;
}