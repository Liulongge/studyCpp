#include<iostream>
#include<map>
#include<string>

using namespace std;

// map基本概念
// 介绍：
// map中所有元素都是pair
// pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
// 所有元素都会根据元素的键值自动排序

// 本质：
// map/multimap 属于关联式容器，底层结构是二叉树实现

// 对 map 容器进行查找数据以及统计数据
// 函数原型
// find(key);      查找 key 是否存在， 返回该键值的元素的迭代器；若不存在，返回 map.end()
// count(key);     统计 key 的元素个数

void printMap(const map<int, int> &m)
{
    // 只读迭代器 consy_iterator
    for(map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key: " << it->first << ", value: " << it->second << " " << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(3, 40));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(4, 40));
    printMap(m1);

    // 查找
    // 找到找不到都会返回 迭代器
    map<int, int>::iterator pos = m1.find(3);
    if( pos != m1.end() )
    {
        cout << "查到了元素 key" << endl;
        cout << "key: " << pos->first << ", value: " << pos->second << endl;
    }
    else
    {
        cout << "没有查到元素 key" << endl;
    }
    // 统计
    // map 不允许插入相同 key 值得 pair，对于count统计而言为 0/1
    // multimap 可能大于1
    int num = m1.count(3);
    cout << "num: " << num << endl;

    multimap<int, int> m2;
    m2.insert(pair<int, int>(1, 10));
    m2.insert(pair<int, int>(3, 30));
    m2.insert(pair<int, int>(3, 40));
    m2.insert(pair<int, int>(2, 20));
    m2.insert(pair<int, int>(4, 40));
    num = m2.count(3);
    cout << "num: " << num << endl; 
}

int main()
{
    test01();
    return 0;
}