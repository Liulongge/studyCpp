#include<iostream>
#include<deque>
#include<string>

using namespace std;

// deque （双端队列, deck）容器
// 功能：
// 双端数组，可以对头端进行插入删除操作

// deque 数据存取
// 功能描述：对deque中的数据的存取操作
// 函数原型：
// at(int idx);     返回索引 idx 所指的数据
// operator[]       返回索引 idx 所指的数据
// front()          返回容器中第一个数据元素
// back()           返回容器中最后一个数据元素

void printDeque(deque<int> &d)
{
    // 只读迭代器 consy_iterator
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    cout << "d1.back() = " << d1.back() << endl;
    cout << "d1.front() = " << d1.front() << endl;
    cout << "d1.at(2) = " << d1.at(2) << endl;
    cout << "d1[2] = " << d1[2] << endl;
}

int main()
{
    cout << "-------- test01 --------" << endl;
    test01();
    return 0;
}