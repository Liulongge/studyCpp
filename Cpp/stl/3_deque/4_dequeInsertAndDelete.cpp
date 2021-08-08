#include<iostream>
#include<deque>
#include<string>

using namespace std;

// deque （双端队列, deck）容器
// 功能：
// 双端数组，可以对头端进行插入删除操作

// deque 
// 功能描述：向 dequeue 容器中插入删除数据

// 函数原型：
// 两端插入操作：
// push_back(elem);     在容器尾部添加一个数据
// push_front(elem);    在容器头部添加一个数据
// pop_back(elem);      删除容器尾部一个数据
// pop_front(elem);     删除容器头部一个数据

// 指定位置操作：
// insert(pos, elem);       在pos位置插入一个elem元素拷贝，返回新数据的位置
// insert(pos, n, elem);    在pos位置插入n个elem数值，无返回值
// insert(pos, beg, end);   在pos位置插入[beg, end)区间的数据，无返回值
// clear();                 清空容器中的所有数据
// erase(beg, end);         删除[beg, end)区间的数据，返回下一个数据的位置
// erase(pos);              删除pos位置的数据，返回下一个数据的位置

// 总结：
// 插入删除提供的位置是迭代器
// 尾插 push_back
// 尾删 pop_back
// 头插 push_front
// 头删 pop_front

void printDeque(deque<int> &d)
{
    // 只读迭代器 consy_iterator
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 两端进行操作，插入删除
void test01()
{
    deque<int> d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    // 头插
    d1.push_front(100);
    d1.push_front(200);

    // 200 100 10 20 
    printDeque(d1);

    // 尾删 200 100 10
    d1.pop_back();
    printDeque(d1);

    // 头删 100 10
    d1.pop_front();
    printDeque(d1);
}

void test02()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    // 插入 一个元素
    d1.insert(d1.begin(), 1000);
    printDeque(d1);
    // 插入 n 个元素
    d1.insert(d1.begin(), 2, 10000);
    printDeque(d1);

    // 插入区间
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);
}

void test03()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    // 删除某一个
    d1.erase(d1.begin() + 1);
    printDeque(d1);

    // 删除某一区间
    d1.erase(d1.begin(), d1.end());
    // d1.clear();
    printDeque(d1);



}

int main()
{
    cout << "-------- test01 --------" << endl;
    test01();
    cout << "-------- test02 --------" << endl;
    test02();
    cout << "-------- test03 --------" << endl;
    test03();
    return 0;
}