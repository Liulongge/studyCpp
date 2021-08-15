#include<iostream>
#include<set>
#include<string>

using namespace std;

// set 容器基本概念
// 介绍：所有元素都会在插入时自动被排序

// 本质：set/multiset属于关联式容器，底层数据结构是用二叉树实现

// pair 对组创建
// 功能描述：成对出现的数据，利用对组可以返回两个数据

// 两种创建方式：
// pair<type, type> p(value1, value2);              默认构造
// pair<tyoe, type> p = make_pair(value1, value2);  make制造

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
    // 第一种方式
    pair<string, int> p("Tom", 20);
    cout << "姓名： " << p.first << "， 年龄： " << p.second << endl;

    // 第二种方式
    pair<string, int> p2 = make_pair("Jerry", 31);
    cout << "姓名： " << p2.first << "， 年龄： " << p2.second << endl;
}

int main()
{
    test01();
    return 0;
}