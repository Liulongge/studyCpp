// std::make_unique 是 C++14 引入的一个标准库函数，用于创建 std::unique_ptr 智能指针。
// 它简化了 std::unique_ptr 的构造，并且避免了潜在的资源泄漏问题。
// std::make_unique 通过在单个表达式中分配和初始化对象来做到这一点，从而确保如果构造函数抛出异常，资源可以被正确地清理。

// std::make_unique 的优势
// 简化代码：减少了手动构造 std::unique_ptr 所需的代码量。
// 安全性：通过使用 std::make_unique 来代替直接调用 new，可以减少因异常导致的资源泄漏风险。
// 可读性：使代码更清晰易懂，因为创建智能指针的过程更加直观。


// 在 std::make_unique 引入之前，即 C++11 及更早版本中，创建 std::unique_ptr 通常需要使用 new 操作符来分配内存，
// 并手动构造 std::unique_ptr。这种方式不仅代码较为冗长，而且容易出错，尤其是在处理复杂类型的对象时。


// 1、创建不带参数的对象：
// std::unique_ptr<T> ptr = std::make_unique<T>();
// 2、创建带有参数的对象：
// std::unique_ptr<T> ptr = std::make_unique<T>(args...);

#include <iostream>
#include <memory>
#include <string>

// 定义一个类
class MyClass {
public:
    MyClass(const std::string& name) : name_(name) {
        std::cout << "MyClass constructor: " << name_ << '\n';
    }
    ~MyClass() {
        std::cout << "MyClass destructor: " << name_ << '\n';
    }

    void sayHello() const {
        std::cout << "Hello from " << name_ << "!\n";
    }

private:
    std::string name_;
};

int main() {
    // 使用 std::make_unique 创建 std::unique_ptr<MyClass>
    auto ptr1 = std::make_unique<MyClass>("Object1");

    // 调用成员函数
    ptr1->sayHello();

    // 使用 std::make_unique 创建带参数的对象
    auto ptr2 = std::make_unique<MyClass>("Object2");
    ptr2->sayHello();

    // 注意：一旦 unique_ptr 超出作用域，它所管理的对象就会自动销毁
    // 这里不需要显式的 delete 或 reset 操作

    // 直接使用 new 创建对象并传递给 unique_ptr
    std::unique_ptr<MyClass> ptr3(new MyClass("Object3"));
    ptr3->sayHello();
    return 0;
}