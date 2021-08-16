#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

// 概述:
// 算法主要是由头文件 <algorithm>,<funcitonal>,<numeric>组成
// <algorithm> 是所有 STL 头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等；
// <numeric> 体积很小，只包含几个在序列上面进行简单数学运算的模板函数；
// <funcitonal> 定义了一些模板类，用以声明函数对象

// 常用遍历算法有：
// 1.for_each    遍历容器
// 2.transform   搬运容器到另一个容器

// transhform：搬运容器到另一个容器
// 函数原型：
// transform(iterator beg1, iterator end1, iterator beg2, _func);
// beg1：      源容器开始迭代器
// end1：      源容器结束迭代器
// beg2：      目标容器开始迭代器
// _func：     函数或者函数对象

// 搬运的目标容器必须要提前开辟空间，否则无法正常搬运

class Transform
{
public:
    int operator()(int val)
    {
        return val + 100;
    }
};

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    // 源容器
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 目标容器，必须提前开辟空间
    vector<int> vTarget;
    vTarget.resize(v.size());
    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << endl;
}

int main()
{
    test01();
    return 0;
}