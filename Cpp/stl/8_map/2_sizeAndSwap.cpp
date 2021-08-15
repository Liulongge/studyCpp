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

// 统计map容器的大小以及交换map容器
// 函数原型
// size();      返回容器中元素数目
// empty();     判断容器是否为空
// swap(mp);    交换两个结合容器

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
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(4, 40));
    printMap(m1);

    // 判断容器是否为空
    if( m1.empty() )
    {
        cout << "m为空" << endl;
    }
    else
    {
        cout << "m不为空" << endl;
        // 查看容器大小
        cout << "m容器大小：" << m1.size() << endl;
    }

    cout << ">>>>>>>> 交换前 <<<<<<<<" << endl;
    map<int, int> m2;
    m2.insert(pair<int, int>(1, 100));
    m2.insert(pair<int, int>(3, 300));
    m2.insert(pair<int, int>(2, 200));
    m2.insert(pair<int, int>(4, 400));
    printMap(m1);
    printMap(m2);

    cout << ">>>>>>>> 交换后 <<<<<<<<" << endl;
    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}


int main()
{
    test01();
    return 0;
}