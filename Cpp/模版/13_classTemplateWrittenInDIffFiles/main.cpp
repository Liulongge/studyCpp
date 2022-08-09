#include<iostream>
#include<string>

// 方法一：直接引用 xxx.cpp 文件
// #include"person.cpp"
// 但是一般在使用中不这么用，不把源码暴露出去

// 方法二：
// 将声明与实现放在同一文件中，命名文 xxx.hpp 
#include"person.hpp"
using namespace std;


// 类模板份文件编写
// 掌握类模板成员函数份文件编写产生的问题以及解决方式

// 问题：
// 类模板中成员函数创建时机是在 调用阶段，导致分文件编写时链接不到
// xxx.cpp中文件不会变编译，在链接阶段是找不到的。

// 解决：
// 解决方式1：直接包含.cpp文件
// 解决方式2：将声明和实现写在同一文件中，并更改后缀名为hpp，hpp是约定的名称，并不是强制

// 总结：主流的解决方法是第二种方法，将类模板成员函数写到一起，并将后缀命名为xxx.hpp

void test01()
{
    Person<string, int> p1("Tom", 20);
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}