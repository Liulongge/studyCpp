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
// set容器进行插入数据和删除数据

// 函数原型：
// insert(elem);      在容器中插入元素
// clear();           清除容器中元素
// erase(pos);        删除pos迭代其所指的元素，返回下一个元素迭代器
// erase(beg, end);   删除区间[beg, end)的所有元素，返回下一个元素的迭代器
// erase(elem);       删除容器中值为elem的元素

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

    // 删除
    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(30);
    printSet(s1);

    // 删除某个区间
    // s1.erase(s1.begin(), s1.end());
    s1.clear();
    printSet(s1);
}

int main()
{
    test01();
    return 0;
}