#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// stl的诞生
// 长久以来，软件界一直希望建立一种可以重复利用的东西
// C++面向对象和范式编程思想，目的就是复用性的提升
// 大多情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
// 为了建立数据结构和算法的一套标准，诞生了STL

// STL基本概念
// STL(Standard Template Library, 标准模板库)
// STL从广义上分为：容器（container）、算法（algorithm）、迭代器（iterator）
// 容器和算法之间通过迭代器进行无缝衔接
// STL几乎所有的代码都采用了模板类或者模板函数

// STL六大组件：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器

// 容器：各种数据结构，如vector,lisr,deque,set,map等用来存放数据
// 算法：各种常用算法，如sort,find,copy,for_each等
// 迭代器：扮演了容器和算法之间的胶合剂
// 仿函数：行为类似函数，可作为算法的某种策略
// 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
// 空间适配器：负责空间配置以及管理


// 容器：置物之所也
// STL容器就是将运用最广泛的一些数据结构实现出来
// 常用的数据结构：数组、链表、树、栈、队列、集合、映射表等
// 这些容器分为：序列式容器 和 关联式容器 两种：
// 序列式容器：强调值得排序，序列式容器中的每个元素均有固定的位置
// 关联式容器：二叉树结构，各个元素之间没有严格的物理上的顺序关系


// 算法：问题之解法也
// 有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法
// 算法分为：质变算法 和 非质变算法
// 质变算法：是指运算过程中会更改区间内的元素的内容，例如拷贝，替换，删除
// 非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找，计数，遍历，寻找极值等


// 迭代器：容器和算法之间粘合剂
// 提供一种方法，使之能够依序寻访某个容器所包含的各个元素，而又无需暴露该容器的内部表示方式
// 每个容器都有自己专属的迭代器
// 迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针

// 迭代器种类
// 输入迭代器     对数据的只读访问                     只读，支持 ++、==、！=
// 输出迭代器     对数据的只写访问                     只写，支持++
// 前向迭代器     读写操作，并能向前推进迭代器           读写，支持++、==、！=
// 双向迭代器     读写操作，并能向前和向后操作           读写，支持++、--
// 随机访问迭代器  读写操作可以以跳跃的方式访问呢任意数据， 读写，支持++、--、[n]、-n、<
//               功能最强的迭代器                     <=、>、>=
                                                  
// 常用的容器中迭代器种类为双向迭代器，和随机访问迭代器


// STL中最常用的容器是为Vector，可以理解为数组。

// 容器：vector
// 算法：for_each
// 迭代器：vector<int>::iterator

// vector 容器存放内置数据类型

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    // 创建了一个vector容器，数组
    vector<int> v;

    // 向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器 指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();     // 结束迭代器 指向迭代其中最后一个元素的写一个位置

    // 1.第一种形式，while形式
    while(itBegin != itEnd) // 如果起始迭代器不等于结束迭代器
    {
        cout << *itBegin << endl;
        itBegin ++;
    }
    // 2.第二种遍历方式
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    // 3.第三种遍历方式、利用 STL 提供遍历算法
    for_each(v.begin(), v.end(), myPrint);
    // 4.下标访问
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
}

int main()
{
    test01();
    return 0;
}