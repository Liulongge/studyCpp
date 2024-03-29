#include<iostream>
#include<deque>
#include<string>

using namespace std;

// deque （双端队列, deck）容器
// 功能：
// 双端数组，可以对头端进行插入删除操作

// deque 赋值操作
// 功能描述：给 deque 容器进行赋值
// 函数原型

// deque& operator=(const deque &deq);  重载等号操作符
// assign(beg, end)                     将[beg, end)区间中的数据拷贝赋值给本身
// assign(n, ele);                      将 n 个 ele 拷贝给本身

// 总结：deque赋值操作也与vector相同

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
    
    // 1.等号赋值，operator=
    deque<int> d2;
    d2 = d1;
    printDeque(d2);

    // 2.assign 赋值
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}