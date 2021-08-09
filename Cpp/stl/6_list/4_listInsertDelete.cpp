#include<iostream>
#include<list>
#include<string>

using namespace std;

// 对 list 容器进行数据的 插入 删除
// 函数原型：
// push_back(elem);             在容末尾加入元素
// pop_back();                  删除容器中最后一个元素
// push_front(elem);            在容器开头插入一个元素
// pop_front();                 从容器开头删除一个元素
// insert(pos, elem);           在 pos 位置插入 elem 元素的拷贝，返回新数据的位置
// insert(pos, n, elem);        在 pos 位置插入 n 个 elem 元素，无返回值
// insert(pos, beg, end);       在 pos 位置插入 [beg, end) 区间的数据，无返回值
// clear()                      移除容器中所有数据
// erase(beg, end);             删除 [beg，end) 区间的数据，返回一个数据位置
// erase(pos);                  删除 pos 位置的数据，返回下一个数据的位置
// remove(elem);                删除容器中所有与 elem 值匹配的元素

// 总结：
// 尾插    push_back
// 尾删    pop_back
// 头插    push_front
// 头删    pop_front
// 插入    insert
// 删除    erase
// 移除    remove
// 清空    clear

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

    // 尾插
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    // 10 20 30 
    printList(l1);

    // 头插
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    // 300 200 100 10 20 30 
    printList(l1);

    // 尾删
    l1.pop_back();
    printList(l1);

    // 头删
    l1.pop_front();
    printList(l1);

    // insert 插入
    list<int>::iterator it = l1.begin(); // 必须提供迭代器
    l1.insert(++it, 888);
    printList(l1);

    // 删除
    it = l1.begin();
    l1.erase(++it);
    printList(l1);

    // 移除
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    printList(l1);
    l1.remove(10000);
    printList(l1);

    // 清空
    l1.clear();
    printList(l1);

}

int main()
{
    test01();
    return 0;
}