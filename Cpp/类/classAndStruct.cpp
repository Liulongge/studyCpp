#include <iostream>

using namespace std;

// C++中 struct 与 class 最大区别在于   默认访问权限的不同
// 区别：
// struct: 默认为公共
// class:  默认为私有

class C1
{
    int m_A;   // 默认权限  私有
};

struct C2
{
    int m_A;   // 默认权限  共有
};

int main(int argc, char *argv[])
{
    C1 c1;
    // c1.m_A = 100;  私有成员不能访问

    C2 c2;
    c2.m_A = 100;  // 在strect中默认权限为共有  可以访问

    return 0;
}