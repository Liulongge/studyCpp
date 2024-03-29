#include<iostream>
#include<list>
#include<string>

using namespace std;

// list 链表 基本
// 功能：将数据进行链式存储
// 链表（list）：是一种物理存储单元的非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

// 链表的组成：链表是由一系列 节点 组成
// 节点的组成：一个是存储数据元素的 数据域，另一个是存储下一个节点地址的 指针域
// STL中的链表是双向训话链表

// 由于链表的存储方式不是连续的内存空间，因此链表 list 中的迭代器只能支持 前移 和 后移,属于 双向迭代器

// list 优点：
// 1.采用动态存储分配，不会造成内存浪费和溢出
// 2.链表执行插入和删除操作十分方便，修改指即可，不需要移动大量元素

// list 缺点
// 链表灵活，但是空间（指针域）和时间（遍历）额消耗大

// list 有一个重要的性质，插入操作和删除操作都不会造成原有list 迭代器的失效，这在vector是不成立的

// 总结： STL中 list 和 vector 是两个最常用的容器，各有优缺点

// 函数原型
// list<T> lst;                list采用模板类实现，对象的默认构造形式
// list(beg, end);             构造函数将[beg, end)区间中的元素拷贝给本身
// list(n, elem);              构造函数将 n 个 elem 拷贝给本身
// list(const list &lst);      拷贝构造函数

void printList(const list<int> &l)
{
    // 只读迭代器 consy_iterator
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // 1.创建 list 容器，默认构造
    list<int> l1;
    // 添加数据
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    printList(l1);

    // 2.区间方式构造
    list<int> l2(l1.begin(), l1.end());
    printList(l2);

    // 3.拷贝构造
    list<int> l3(l2);
    printList(l3);

    // 4.n 个 elem
    list<int> l4(10, 1000);
    printList(l4);
}

int main()
{
    test01();
    return 0;
}