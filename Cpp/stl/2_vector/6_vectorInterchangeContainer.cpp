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

// vector互换容器
// 功能描述： 实现两个迭代器内元素的互换
// 函数原型： swap(vec); 将 vec 与本身的元素互换 

// 总结：swap可以使两个容器互换，可以达到实际使用的收缩内存的效果

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
    // 1.基本使用
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "交换前：" << endl;
    printVector(v1);

    vector<int> v2;
    for(int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    cout << "交换后" << endl;

    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

void test02()
{
    // 2.实际使用，收缩内存
    vector<int> v;
    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v的容量: " << v.capacity() << ", v的大小: " << v.size() << endl;

    v.resize(3); // 重新指定大小，容量没有变小 131072，大小变小了 3
    // v的容量: 131072, v的大小: 3
    cout << "v的容量: " << v.capacity() << ", v的大小: " << v.size() << endl;

    // 巧用 swap 收缩内存
    vector<int> (v).swap(v);
    cout << "v的容量: " << v.capacity() << ", v的大小: " << v.size() << endl;
    // vector<int> (v); 匿名构造，创建匿名对象，匿名对象，当前行执行完毕后，会被释放
    // vector<int> (v).swap(v); 互换元素，容器之间的交换
}

int main()
{
    test01();
    test02();
    return 0;
}