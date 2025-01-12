
// 在C++中，派生类（如B类）可以直接访问基类（如A类）的保护成员（protected），但不能直接访问基类的私有成员（private）。
// 然而，派生类可以被声明为基类的友元类，从而获得访问基类私有成员的能力。
// 这意味着你可以将B类声明为A类的友元，使得B不仅继承了A，还可以访问A的私有成员。

#include <iostream>

class A {
private:
    int privateData = 10;

protected:
    int protectedData = 20;

public:
    friend class B; // 声明B为A的友元
};

class B : public A {
public:
    void showPrivate() const {
        std::cout << "A's private data: " << privateData << std::endl;
    }

    void showProtected() const {
        std::cout << "A's protected data: " << protectedData << std::endl;
    }
};

int main() {
    B b;
    b.showPrivate();  // 可以访问A的私有成员
    b.showProtected(); // 可以访问A的保护成员

    return 0;
}