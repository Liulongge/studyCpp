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

// map 容器默认排序规则为 按照 key 值进行从小到大排序
// 主要技术点：
// 利用仿函数，可以改变排序规则

class MyCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void printMap(const map<int, int, MyCompare> &m)
{
    // 只读迭代器 consy_iterator
    for(map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key: " << it->first << ", value: " << it->second << " " << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int, MyCompare> m1;
    m1.insert(make_pair(1, 10));
    m1.insert(make_pair(3, 30));
    m1.insert(make_pair(2, 20));
    m1.insert(make_pair(4, 40));
    m1.insert(make_pair(5, 50));
    // 变为了 降序
    printMap(m1);
}

int main()
{
    test01();
    return 0;
}