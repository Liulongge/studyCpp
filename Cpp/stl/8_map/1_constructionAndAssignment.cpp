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

// 优点：
// 可以根据key值快速找到value值

// map和multimap区别：
// map不允许容器中有重复key值元素
// multimap允许容器中有重复key值元素

// map的构造和赋值
// 功能描述：
// 对map容器进行构造和赋值
// 函数原型
// 构造
// map(T1, T2) mp;         map默认构造函数
// map(const map &mp);     拷贝构造函数

// 赋值：
// map& operator=(const map &mp);   重载等号操作符

// 总结：map中所有数据都成对存在，插入数据时候要使用对组 pair

void printMap(const map<int, int> &s)
{
    // 只读迭代器 consy_iterator
    for(map<int, int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "key: " << it->first << ", value: " << it->second << " " << endl;
    }
    cout << endl;
}

void test01()
{
    // 默认构造
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(4, 40));
    printMap(m);
    // 拷贝构造
    map<int, int> m2(m);
    printMap(m2);

    // 赋值
    map<int, int> m3;
    m3 = m;
    printMap(m3);
}

int main()
{
    test01();
    return 0;
}