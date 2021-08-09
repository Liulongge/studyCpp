#include<iostream>
#include<list>
#include<string>

using namespace std;

// list 容器的赋值和交换

// 函数原型：
// assign(beg, end);                    将[beg, end)区间中的数据拷贝赋值给本身
// sssign(n, elem);                     将 n 个 elem 拷贝赋值给本身
// list& operator=(const list &lst);    重载 等号 运算符
// swap(lst);                           将 list 与本身的元素互换


void printList(const list<int> &l)
{
    // 只读迭代器 consy_iterator
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // 1.创建 list 容器，默认构造
    list<int> l1;
    // 添加数据
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    cout << "l1 :";
    printList(l1);

    // 等号赋值
    list<int> l2;
    l2 = l1;
    cout << "l2 :";
    printList(l2);

    // assign
    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    cout << "l3 :";
    printList(l3);

    // assign
    list<int> l4;
    l4.assign(10, 100);
    cout << "l4 :";
    printList(l4);

    // 交换 swap
    cout << "---- 交换后 ----" << endl;
    l3.swap(l4);
    cout << "l4 :";
    printList(l4);
    cout << "l3 :";
    printList(l3);
}

int main()
{
    test01();
    return 0;
}