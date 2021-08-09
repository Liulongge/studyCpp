#include<iostream>
#include<list>
#include<string>

using namespace std;

// list 容器数据存取

// 函数原型
// front();    返回一个元素
// back();     返回最后一个元素

// 总结：
// list 中不可以利用 [] 与 at() 方式访问数据
// 返回第一个元素     front
// 返回最后一个元素   back

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
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    cout << "l1.front: " << l1.front() << endl;
    cout << "l1.back: " << l1.back() << endl;

    // l1[0]     不可以用 [] 访问list容器中元素
    // l1.at(0)  不可以用 at() 访问list容器中元素
    // 原因是 list 本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问
    
    // 验证迭代器不支持随机访问
    list<int>::iterator it = l1.begin();
    // it = it + 1;  // 没有与之匹配的 + 号运算符
    // 仅支持，++  -- 往前，往后走，递增，递减


}

int main()
{
    test01();
    return 0;
}