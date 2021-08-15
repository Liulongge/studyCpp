#include<iostream>
#include<set>
#include<string>

using namespace std;

// set 容器基本概念
// 介绍：所有元素都会在插入时自动被排序

// 本质：set/multiset属于关联式容器，底层数据结构是用二叉树实现

// set与multiset区别
// set不允许容器中有重复的元素
// multiset允许有重复的元素

// 功能描述：
// 统计set容器大小以及交换set容器

// 函数原型：
// size();        返回容器中元素数目
// empty();       判断容器是否为空
// swap(st);      交换两个集合容器

void printSet(const set<int> &s)
{
    // 只读迭代器 consy_iterator
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    // 插入数据只有insert数据
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);
    // 10 20 30 40
    printSet(s1);

    // 判断容器是否为空
    if( s1.empty() )
    {
        cout << "s1为空" << endl;
    }
    else
    {
        cout << "s1不为空" << endl;
        // 查看容器大小
        cout << "set容器大小：" << s1.size() << endl;
    }

    set<int> s2;
    s2.insert(100);
    s2.insert(300);
    s2.insert(200);
    s2.insert(400);
    cout << ">>>>>>>> 交换前 <<<<<<<<" << endl;
    printSet(s1);
    printSet(s2);

    cout << ">>>>>>>> 交换后 <<<<<<<<" << endl;
    s2.swap(s1);
    printSet(s1);
    printSet(s2);
}

int main()
{
    test01();
    return 0;
}