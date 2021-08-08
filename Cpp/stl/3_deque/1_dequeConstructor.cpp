#include<iostream>
#include<deque>
#include<string>

using namespace std;

// deque （双端队列, deck）容器
// 功能：
// 双端数组，可以对头端进行插入删除操作

// deque 与 vector 区别：
// 1.vector 对于头部的插入删除效率低，数据量越大，效率越低，需要进行数据拷贝移位
// 2.deque 相对而言，对于头部的插入删除速度比 vector 快
// 3.vector 访问元素时的速度比 deque 快，这和两者内部实现有关

// deque 内部工作原理：
// deque 内部有一个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
// 中控器 维护的是每一个缓冲区的地址，使得使用 deque 时像一片连续的内存空间

// queue 容器的迭代器支持随机访问

// deque 构造函数
// 功能描述： deque 容器构造
// 函数原型：
// deque<T> deqT;              默认构造函数
// deque(beg, end);            构造函数经[beg, end)区间中的元素拷贝给自身
// deque(n, ele);              构造函数将 n 个 ele 拷贝给自身
// deque(const deque &deq);    拷贝构造函数

// 总结：const_iterator 只读迭代器

void printDeque(deque<int> &d)
{
    // 只读迭代器 consy_iterator
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // 1.默认构造函数
    deque<int> d1;
    for(int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // 2.构造函数经[beg, end)区间中的元素拷贝给自身
    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    // 3.构造函数将 n 个 ele 拷贝给自身
    deque<int> d3(10, 100);
    printDeque(d3);

    // 4.拷贝构造函数
    deque<int> d4(d3);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}