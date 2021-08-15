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
// 逻辑仿函数：实现逻辑运算

// 用法：
// 这些仿函数所产生的对象，用法和一般函数完全相同
// 使用内建函数对象，需要引入头文件 #include<functional>

// 仿函数原型：
// template<class T> bool logical_and<T>         逻辑与
// template<class T> bool logical_or<T>          逻辑或   
// template<class T> bool logical_not<T>         逻辑非

// 总结：逻辑仿函数实际使用中比较少用，了解即可

void printVector(const vector<bool> &v)
{
    // 只读迭代器 consy_iterator
    for(vector<bool>::const_iterator it = v.begin(); it != v.end(); it++)
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
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    printVector(v);

    // 利用逻辑非，将容器v 搬运到容器 v2中，并执行取反操作
    vector<bool> v2;
    v2.resize(v.size()); // 先开辟空间，定义v2之后，v2并没有空间
    // 逻辑取反操作
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    printVector(v2);
}

int main()
{
    test01();
    return 0;
}