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


// for_each：实现容器的遍历
// 函数原型：
// for_each(iterator beg, iterator end, _func);
// 遍历算法，遍历容器元素
// beg   开始迭代器
// end   结束迭代器
// _func 函数或者函数对象

// 总结：for_each 在实际开发中是最长用的遍历算法
// _func 为普通函数时，不需要（），仿函数需要（），传一个函数对象进去

// 普通函数
void print01(int val)
{
    cout << val << " ";
}

// 仿函数
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 普通函数不需要括号
    for_each(v.begin(), v.end(), print01);
    cout << endl;
    // 仿函数需要括号，传一个匿名函数对象
    for_each(v.begin(), v.end(), print02());
    cout << endl;
}

int main()
{
    test01();
    return 0;
}