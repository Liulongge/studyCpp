#include<iostream>
#include<list>
#include<string>

using namespace std;

// list 容器中的单转和排序

// 函数原型：
// reverse();       反转
// sort();          排序

// 反转    reverse
// 排序    sort  (成员函数)

void printList(const list<int> &l)
{
    // 只读迭代器 consy_iterator
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int v1, int v2)
{
    // 降序，让第一个属大于第二个数
    return v1 > v2;
};

void test01()
{
    list<int> l1;

    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);
    cout << "-------- 反转前 --------" << endl;
    printList(l1);

    // 反转
    l1.reverse();
    cout << "-------- 反转后 --------" << endl;
    printList(l1);

    // 排序
    // 所有不支持随机访问的迭代器，不支持标准算法
    // 不支持随机访问迭代器的容器，内部会提供一些算法
    // sort(l1.begin(), l1.end()); // 全局函数
    l1.sort();  // 默认排序规则，从小到大  成员函数
    cout << "-------- 升序排序后 --------" << endl;
    printList(l1);

    l1.sort(myCompare);
    cout << "-------- 降序排序后 --------" << endl;
    printList(l1);

}

int main()
{
    test01();
    return 0;
}