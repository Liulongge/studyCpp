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

// map容器插入与删除
// 函数原型
// insert(elem);      在容器中插入元素，4种方式
// clear();           清除所有元素
// erase(pos);        删除pos迭代其所指的元素，返回下一个元素迭代器
// erase(beg, end);   删除区间[beg, end)的所有元素，返回下一个元素的迭代器
// erase(elem);       删除容器中值为key的元素


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
    // 1.插入
    // 插入，第一种
    m1.insert(pair<int, int>(1, 10));
    // 插入，第二种
    m1.insert(make_pair(2, 20));
    // 插入，第三种，不建议使用，太复杂
    m1.insert(map<int, int>::value_type(3, 30));
    // 插入，第四种，不建议使用
    m1[4] = 40;
    // 输出为 0 
    // 如果插入数据，插入错误的话，会创建为 0的 value
    // 插入不太好，可以采用中括号进行 查询
    cout << m1[5] << endl;
    printMap(m1);

    // 2.删除
    // 根据迭代器
    m1.erase(m1.begin());
    printMap(m1);

    // 根据 key值
    m1.erase(3);
    // m1.erase(40); // 只会根据 key 值进行删除，不会根据 value，如果 key 值存在则删除，不存在则不做处理
    printMap(m1);

    // 区间删除
    // m1.erase(m1.begin(), m1.end());
    m1.clear();
    printMap(m1);
}

int main()
{
    test01();
    return 0;
}