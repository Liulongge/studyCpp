#include<iostream>
#include<list>
#include<string>

using namespace std;

// list 容器的大小操作

// 函数原型：
// size();              返回容器中元素的个数
// empty();             判断容器是否为空
// resize(num);         重新指定容器的长度为 num，若容器变长，则默认值田中新位置。
//                                            若容器变短，则末尾超出容器长度的元素被删除。
// resize(num, elem);   重新指定容器的长度为 num，若容器变长，则以 elem 值填充新位置。
//                                            若容器变短，则末尾超出容器长度的元素被删除。

// 总结：
// 判断是否为空  empty
// 返回元素个数  size
// 重新指定个数  resize

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
    // 添加数据
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    if( l1.empty() )
    {
        cout << "l1 为空" << endl;
    }
    else
    {
        cout << "l1 不为空" << endl;
        cout << "l1 的个数: " << l1.size() << endl;
    }

    // 重新指定个数
    l1.resize(10);
    // l1.resize(10, 10000);
    printList(l1);

    l1.resize(2);
    printList(l1);
}

int main()
{
    test01();
    return 0;
}