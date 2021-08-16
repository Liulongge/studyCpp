#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

// 常用查找算法
// 算法简介
// find             查找元素
// find_if          按条件查找元素
// adjacent_find    查找相邻重复元素
// binary_search    二分查找法
// count            统计元素个数
// count_if         按条件统计元素个数

// find_if：按条件查找元素
// 函数原型：
// find_if(iterator beg, iterator end, _Pred)
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// _Pred  函数或者谓词（返回 bool类型仿函数）

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    string m_Name;
    int m_Age;
};

class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age > 20;
    }
};

class GreaterFIve
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

// 查找内置数据类型
void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFIve());
    if( it == v.end() )
    {
        cout << "没有找到！" << endl;
    }
    else
    {
        cout << "找到了！" << *it << endl;
    } 
}

// 查找自定义数据类型
void test02()
{
    vector<Person> v;
    Person p1("AA", 100);
    Person p2("BB", 200);
    Person p3("CC", 300);
    Person p4("DD", 400);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
    if( it == v.end() )
    {
        cout << "没有找到！" << endl;
    }
    else
    {
        cout << "找到了！" << it->m_Name << ": " << it->m_Age << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}