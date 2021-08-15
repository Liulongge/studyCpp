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

// set构造和赋值
// 功能描述：创建set容器以及赋值
// 构造：
// set<T> st;           默认构造函数
// set(const set &set); 拷贝构造函数

// 赋值：
// set& operator=(const set &set); 重载等号操作符

// 总结：set容器插入数据时用 insert
// set 容器插入数据的数据会自动排序

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
    // set容器特点：
    // 所有元素插入时自动被排序
    // set 容器不允许插入重复值
    printSet(s1);

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);
}

int main()
{
    test01();
    return 0;
}