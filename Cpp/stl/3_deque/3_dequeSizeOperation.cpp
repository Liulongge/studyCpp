#include<iostream>
#include<deque>
#include<string>

using namespace std;

// deque （双端队列, deck）容器
// 功能：
// 双端数组，可以对头端进行插入删除操作

// 功能描述：对 deque 容器大小操作

// 函数原型
// deque.empty();              判断容器是否为空
// deque.size()                返回容器中元素的个数
// deque.resize(num);          重新指定容器的长度为num，若容器变长，则以默认值填充新位置
//                                                  若容器变短，则末尾超出容器长度的元素被删除
// deque.resize(num, ele);     重新指定容器的长度为num，若容器变长，则以elem填充新位置
//                                                   若容器变短，则末尾超出容器长度的元素被删除

// 总结：
// deque 没有容量概念
// 判断是否为空 empty
// 返回元素个数 size
// 重新指定个数 resize

void printDeque(deque<int> &d)
{
    // 只读迭代器 consy_iterator
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// deque 容器的赋值操作
void test01()
{
    deque<int> d1;
    for(int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    if(d1.empty())
    {
        cout << "d1 为空" << endl;
    }
    else
    {
        cout << "d1 不为空" << endl;
        cout << "d1 的大小为" << d1.size() << endl;
    }
    // deque 容器没有 容量的概念
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);

}

int main()
{
    test01();
    return 0;
}