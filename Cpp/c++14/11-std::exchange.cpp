// std::exchange 是 C++14 引入的一个实用函数模板，位于 <utility> 头文件中。它提供了一种简便的方法来交换一个对象的值，
// 并返回该对象原来的值。这在需要更新一个变量的同时获取其旧值的情况下非常有用。

// template< class T, class U = T >
// T exchange( T& obj, U&& new_value );


// std::exchange 的作用
// 简化代码：通过单个函数调用完成值的替换和旧值的返回，减少了多行代码的需求。
// 原子操作：对于某些类型的对象，std::exchange 可以保证操作是原子性的，即不会被其他线程干扰。
// 提高可读性：使意图更加明确，读者一眼就能明白代码的目的，即替换并获取旧值。

#include <iostream>
#include <utility> // 包含 std::exchange

int main() {
    int originalValue = 5;
    int newValue = 10;

    // 使用 std::exchange 更新 originalValue 并获取它的旧值
    int oldValue = std::exchange(originalValue, newValue);

    std::cout << "Original value was: " << oldValue << '\n';
    std::cout << "New value is: " << originalValue << '\n';

    // 演示使用默认初始化值
    std::string str = "Hello";
    std::string oldStr = std::exchange(str, std::string()); // 空字符串

    std::cout << "Original string was: '" << oldStr << "'\n";
    std::cout << "New string is: '" << str << "'\n";

    return 0;
}