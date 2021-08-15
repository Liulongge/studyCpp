#include<iostream>
#include<set>
#include<string>

using namespace std;

// set 容器基本概念
// 介绍：所有元素都会在插入时自动被排序

// 本质：set/multiset属于关联式容器，底层数据结构是用二叉树实现

// 功能描述：
// 对set容器进行查找数据以及统计数据

// 函数原型：
// find(key);      查找key是否存在，若存在，返回改键的元素的迭代器，若不存在，返回set.end();
// count(key);     统计key的元素的个数，set返回 0/1， multiset返回 >= 0

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
    s1.insert(30);
    s1.insert(40);
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    //遍历 10 20 30 40
    printSet(s1);

    set<int>::iterator pos = s1.find(30);
    if( pos != s1.end() )
    {
        cout << "找到元素： " << *pos << endl;
    }
    else
    {
        cout << "未找到元素： " << *pos << endl;
    }
    // 统计个数
    cout << "set容器中元素个数统计：" << s1.count(20) << endl;

    multiset<int> s2;
    // 插入数据只有insert数据
    s2.insert(30);
    s2.insert(40);
    s2.insert(10);
    s2.insert(20);
    s2.insert(30);
    cout << "multiset中元素个数统计：" << s2.count(30) << endl;
}

int main()
{
    test01();
    return 0;
}