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

// vector 赋值操作
// 功能描述：给vector容器进行赋值

// 函数原型
// vector& operator=(const vector &vec);    重载符号操作
// assign(beg, end);                        将[beg, end)区间中数据拷贝赋值给本身
// assign(n, elem);                         将 n 个 elem 拷贝给本身

// 总结：vector 赋值方式比较简单，使用 operator=，或者assign 都可以

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
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 1.赋值 operator=
    vector<int> v2;
    v2 = v1;
    printVector(v2);

    // 2.assign 
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    // 3.n 个 elem 方式赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}