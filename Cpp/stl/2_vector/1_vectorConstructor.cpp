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

// vector 构造函数
// 函数原型
// vector<T> v;                    采用模板实现类实现，默认构造函数
// vector(v.begin(), v.end());     将v[begin(),end()) 前闭后开区间 中俄元素拷贝给自身
// vector(n, elem);                构造函数将n个elem拷贝给自身
// vector(const vector &vec);      拷贝构造函数

// 总结：多种构造方式，灵活使用即可
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
    // 1.默认构造（无参构造）
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 2.通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // 3.n 个 elem 方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    // 4.拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}