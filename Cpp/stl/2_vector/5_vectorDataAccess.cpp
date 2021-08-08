#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 容器的基本概念
// 功能
// vector 数据结构和数组非常类似，也称为 单端数组

// vector 与 普通数组区别
// 不同之处在于数组是静态空间，而vector可以动态扩展

// 动态扩展：
// 1.并不是在原始空间之后续接新空间，而是找到更大的内存空间，然后将原始数据拷贝新空间，释放原空间
// 2.vector 容器的迭代器是 支持随机访问 的迭代器

// vector 数据存取
// 对vector中数据的存放操作

// 函数原型
// at(int idx)  返回索引 idx 所指的数据
// operator[]   返回所以 idx 所指的数据，重载[]
// front()      返回容器中第一个数据元素
// back()       返回容器中最后一个数据元素

// 总结：
// 除了用迭代器获取 vector中容器中元素，[] 和 at 也可以。1.迭代器， 2.[]， 3.at
// front 返回容器中第一个元素
// back  返回容器中最后一个元素

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    // 尾插法
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    // 1.利用中括号[] 方式访问数组中元素
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    // 2.利用 at 方式访问vector中元素
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    // 获取 第一个/最后一个元素
    cout << "第一个元素为： " << v1.front() << endl;
    cout << "最后一个元素为： " << v1.back() << endl;
}

int main()
{
    test01();
    return 0;
}