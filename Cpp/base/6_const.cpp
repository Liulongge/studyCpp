// 总结：
// "左定值，右定向，const修饰不变量"


// const 是 constant 的缩写，本意是不变的，不易改变的意思。
// 在 C++ 中是用来修饰内置类型变量，自定义对象，成员函数，返回值，函数参数。
// C++ const 允许指定一个语义约束，编译器会强制实施这个约束，允许程序员告诉编译器某值是保持不变的。
// 如果在编程中确实有某个值保持不变，就应该明确使用const，这样可以获得编译器的帮助。

#include <iostream>

// 1. const修饰普通类型的变量
void func1()
{
    const int  a = 7; 
    int  b = a; // 正确
    // a = 8;       // 错误，不能改变
}

typedef struct
{
    int a;
    int b;
} test_const;

// 2. const 修饰指针变量
// const 修饰指针变量有以下三种情况: 
// A: const 修饰指针指向的内容，则内容为不可变量。
// B: const 修饰指针，则指针为不可变量。
// C: const 修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量。
void func2()
{
    // 对于 A, 修饰指针指向的内容，则内容为不可变量。
    // 则指针指向的内容 8 不可改变。
    // 左定值，因为 const 位于 * 号的左边。
    int a = 8;
    const int *p1 = &a;
    // *p1 = 10; // 错误, read-only variable is not assignable
    test_const struce_a = {0, 0};
    const test_const *p3 = &struce_a;
    // p3->a = 10; // 错误, error: cannot assign to variable 'p3' with const-qualified type 'const test_const *'

    // 对于 B, 修饰指针，则指针为不可变量。
    // 右定向。因为 const 位于 * 号的右边
    int b = 8;
    int *const p2 = &b;
    *p2 = 9; // 正确
    int  c = 7;
    // p2 = &c; // 错误, error: cannot assign to variable 'p2' with const-qualified type 'int *const'

    // 对于 C: 则是 A 和 B的合并, 修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量
    int d = 8;
    const int *const p = &d;
    int e = 10;
    // *p = 10; // 错误, error: read-only variable is not assignable
    // p = &e;  // 错误, error: cannot assign to variable 'p' with const-qualified type 'const int *const'

}
int main()
{
    func1();
    func2();
    return 0;
}