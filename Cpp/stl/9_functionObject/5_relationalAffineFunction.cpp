#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

// 内建函数对象
// 概念：STL中内建一些函数对象

// 分类：
// 算数仿函数：实现算数运算
// 关系仿函数：实现关系对比
// 逻辑仿函数

// 用法：
// 这些仿函数所产生的对象，用法和一般函数完全相同
// 使用内建函数对象，需要引入头文件 #include<functional>

// 仿函数原型：
// template<class T> bool equal_to<T>           等于
// template<class T> bool not_equal_to<T>       不等于
// template<class T> bool greater<T>            大于
// template<class T> bool greater_equal<T>      大于等于
// template<class T> bool less<T>               小于
// template<class T> bool less_equal<T>         小于等于

void printVector(const vector<int> &v)
{
    // 只读迭代器 consy_iterator
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class MyCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(2);
    printVector(v);
    // 降序
    // 自己实现 仿函数
    // sort(v.begin(), v.end(), MyCompare());
    // 系统提供 greater 内建函数
    sort(v.begin(), v.end(), greater<int>());
    printVector(v);
}

int main()
{
    test01();
    return 0;
}