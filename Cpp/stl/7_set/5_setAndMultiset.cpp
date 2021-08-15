#include<iostream>
#include<set>
#include<string>

using namespace std;

// set 容器基本概念
// 介绍：所有元素都会在插入时自动被排序

// 本质：set/multiset属于关联式容器，底层数据结构是用二叉树实现

// 区别：
// set不可以插入重复元素，而multiset可以
// set插入数据的同时会返回插入结果，表示插入是否成功
// multiset不会检测数据，因此可以插入重复数据

// 总结：
// 1.如果不允许插入重复数据，可以利用 set
// 2.如果需要插入重复数据，利用multiset

void printSet(const set<int> &s)
{
    // 只读迭代器 consy_iterator
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void printMultiset(const multiset<int> &s)
{
    // 只读迭代器 consy_iterator
    for(multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // 不允许插入相同值
    // set  insert 有返回值
    set<int> s1;
    pair<set<int>::iterator, bool> ret = s1.insert(30);
    if(ret.second)
    {
        cout << "第一次插入成功" << endl;
    }
    else
    {
        cout << "第一次插入失败" << endl;
    }

    ret = s1.insert(30);
    if(ret.second)
    {
        cout << "第二次插入成功" << endl;
    }
    else
    {
        cout << "第二次插入失败" << endl;
    }

    // 允许插入相同值
    // multiset  insert没有返回值
    multiset<int> s2;
    s2.insert(10);
    s2.insert(10);
    s2.insert(10);
    s2.insert(10);
    printMultiset(s2);
}

int main()
{
    test01();
    return 0;
}