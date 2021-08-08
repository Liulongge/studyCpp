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

// vector 预留空间
// 功能描述：减少 vector 在动态扩展容量时的扩展次数

// 函数原型：
// reserve(int len); 容器预留 len 个元素长度，预留位置不初始化，元素不可访问

// 总结：如果数据量比较大，可以一开始就利用 reserve 预留空间，避免多次申请，拷贝

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
    vector<int> v;
    // v.reserve(100000);
    int num = 0;
    int *p = nullptr;
    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        // 判断开辟了多少次内存，每次开辟新内存，首地址会改变
        if(p != &v[0])
        {
            p = &v[0];
            num ++;
        }
    }
    // num = 18; 期间开辟了 18 次空间，拷贝了多次数据
    // 使用 reserve， num = 1, 一下子把空间预留出来，不用再去重复动态操作
    cout << "num = " << num << endl;
}

int main()
{
    test01();
    return 0;
}