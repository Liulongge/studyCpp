#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

// deque （双端队列, deck）容器
// 功能：
// 双端数组，可以对头端进行插入删除操作

// deque排序
// 功能描述：利用排序算法实现对 deque 容器进行排序

// 算法：
// sort(iterator beg, iterator end) 对 beg 和 end 区间内元素进行排序

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
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    cout << "-------- 排序前 --------" << endl;
    printDeque(d);
    cout << "-------- 排序后 --------" << endl;
    // 对于支持随机访问的迭代器的容器，都可以利用 sort 算法直接对其进行排序
    // vector 容器也可以利用 sort 进行排序
    sort(d.begin(), d.end());
    printDeque(d);
}

int main()
{
    test01();
    return 0;
}