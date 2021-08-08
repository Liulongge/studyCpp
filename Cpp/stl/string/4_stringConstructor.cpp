#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// stl的诞生
// 长久以来，软件界一直希望建立一种可以重复利用的东西
// C++面向对象和范式编程思想，目的就是复用性的提升
// 大多情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
// 为了建立数据结构和算法的一套标准，诞生了STL

// string 基本概念
// 本质：
// string 是C++风格字符串，而string本质是一个类

// string 和 char* 区别
// cha* 是一个指针
// string 是一个类，类内部封装了 char*，管理这个字符串，是一个 char*型 的容器

// 特点：
// string 类内部封装了很多成员方法
// 例如：查找 find，拷贝 copy，删除 delete，替换 replace，插入 insert
// string 管理 char* 所分配的内存，不用担心赋值越界 和 取值越界等，由类内部负责

// string 构造函数: 4 种
// 构造函数原型
// string();                   创建一个空的字符串，例如: string str;
// string(const char* s);      使用字符串 s 初始化
// string(const string& str);  使用一个 string 对象初始化另一个 string 对象
// string(int n, char c);      使用 n 个字符串 c 初始化

void test01()
{
    string s1; // 默认构造
    const char* str= "Hello World!";
    string s2(str);
    string s3(s2);
    string s4(6, '6');

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}

int main()
{
    test01();
    return 0;
}