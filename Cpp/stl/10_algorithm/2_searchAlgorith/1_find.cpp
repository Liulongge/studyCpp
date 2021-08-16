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

// find 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器 end()

// 函数原型：
// find(iterator beg, iterator end, value);
// 按值查找元素，找到返回迭代器，找不到返回结束迭代器的位置
// beg     开始迭代器
// end     结束迭代器
// value   查找的元素

// 总结：利用find可以在容器中找指定的元素，返回值是迭代器

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    // 重载 == 让底层find知道如何对比person数据类型
    bool operator==(const Person & p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};

// 查找内置数据类型
void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if( it == v.end() )
    {
        cout << "没有找到！" << endl;
    }
    else
    {
        cout << "找到了！" << endl;
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

    vector<Person>::iterator it = find(v.begin(), v.end(), p2);
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