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

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找容器中没有有大于 5 的数据
    // GreaterFive()：匿名函数对象
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
    if( pos== v.end() )
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到大于 5 的数字为： " <<  *pos  << endl;
    }
}

int main()
{
    test01();
    return 0;
}