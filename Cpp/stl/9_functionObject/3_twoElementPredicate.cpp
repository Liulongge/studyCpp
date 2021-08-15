#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 谓词：
// 概念：
// 返回 bool 类型的仿函数称为 谓词
// 如果 operator() 接受一个参数，那么叫作 一元谓词
// 如果 operator() 接受两个参数，那么叫作 二元谓词

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
    for(int i = 10; i > 0; i--)
    {
        v.push_back(i);
    }

    sort(v.begin(), v.end());
    printVector(v);

    // 使用函数对象（仿函数），改变算法策略，变为排序规则为从大到小
    // MyCompare()：匿名函数对象
    sort(v.begin(), v.end(), MyCompare());
    printVector(v);
}

int main()
{
    test01();
    return 0;
}