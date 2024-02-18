// 头文件：<memory>
// std::shared_ptr: 共享的智能指针
// std::unique_ptr: 独占的智能指针
// std::weak_ptr: 弱引用的智能指针，他不共享指针，并不能操作资源，是用来监视shared_ptr的

// 1、共享智能指针是指多个智能指针可以同时管理同一块有效的内存，共享智能指针shared_ptr是一个模板类，
// 初始化方法：1、通过构造函数；2、std::make_shared辅助函数以及reset方法。
// use_count: 查看有多少个智能指针同时管理着这块内存
// a.通过构造函数初始化：
// std::shared_ptr<T> 智能指针名字(创建堆内存)
// std::shared_ptr<int> ptr1(new int(250));
// b.通过拷贝构造或移动构造初始化
// 拷贝构造：std::shared_ptr<int> ptr2(ptr1)
// 拷贝构造：std::shared_ptr<int> ptr3 = ptr2;
// 移动构造：std::shared_ptr<int> ptr4(std::move(ptr1));
// 移动构造：std::shared_ptr<int> ptr5 = std::move(ptr1);
// c.通过std::make_shared初始化
// template<class T, class... Args>
// shared_ptr<T> make_shared(Args&&... args);
// T：模板参数的数据类型
// Args&&... args：要初始化的数据，如果通过make_shared创建对象，需要按照构造函数的参数列表指定
// d.通过reset方法初始化
// 共享智能指针提供std::shared_ptr::reset方法

#include<memory>
#include<iostream>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "construct Test ..." << endl;
    }
    Test(int x):m_num(x)
    {
        cout << "construct Test, x = " << x << endl;
    }
    Test(string str)
    {
        cout << "construct Test, str = " << str << endl;
    }
    ~Test()
    {
        cout << "deconstruct Test, ..." << endl;
    }
    void setValue(int v)
    {
        m_num = v;
    }
    void print()
    {
        cout << "m_num: " << m_num << endl;
    }
private:
    int m_num;
};

int main()
{
    // 通过构造函数初始化
    shared_ptr<int> ptr1(new int(3));
    cout << "ptr1 use_count: " << ptr1.use_count() << endl;
    // 通过移动构造和拷贝狗仔函数初始化
    shared_ptr<int> ptr2 = std::move(ptr1);
    cout << "ptr1 use_count: " << ptr1.use_count() << endl;
    cout << "ptr2 use_count: " << ptr2.use_count() << endl;

    shared_ptr<int> ptr3 = ptr2;
    cout << "ptr2 use_count: " << ptr2.use_count() << endl;
    cout << "ptr3 use_count: " << ptr3.use_count() << endl;

    // 通过std::make_shared初始化
    shared_ptr<int> ptr4 = make_shared<int>(8);
    cout << "ptr4 use_count: " << ptr4.use_count() << endl;
    shared_ptr<Test> ptr5 = make_shared<Test>(8);
    shared_ptr<Test> ptr6 = make_shared<Test>("Hello World");
    // cout << "ptr5 use_count: " << ptr5.use_count() << endl;
    return 0;
}