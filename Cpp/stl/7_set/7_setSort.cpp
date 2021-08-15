#include<iostream>
#include<set>
#include<string>

using namespace std;

// set 容器基本概念
// 介绍：所有元素都会在插入时自动被排序

// 本质：set/multiset属于关联式容器，底层数据结构是用二叉树实现

// pair 对组创建
// 功能描述：成对出现的数据，利用对组可以返回两个数据

// set 容器默认排序规则为从小到大，掌握如何改变排序规则
// 利用仿函数，改变排序规则

// set容器的排序，内置数据类型

// 总结：对于自定义数据类型，set必须指定排序规则才可以插入数据

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class comparePerson
{
public:
    bool operator()(const Person& p1, const Person &p2)
    {
        return p1.m_Age > p2.m_Age;
    }
};

void printSet(const set<int> &s)
{
    // 只读迭代器 consy_iterator
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void printSetPair(const set<int, MyCompare> &s)
{
    // 只读迭代器 consy_iterator
    for(set<int, MyCompare>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void printSetPerson(const set<Person, comparePerson> &s)
{
    // 只读迭代器 consy_iterator
    for(set<Person, comparePerson>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << it->m_Name << " " << it->m_Age << "" << endl;
    }
}

// 1.内置数据类型
void test01()
{
    set<int> s1;
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(10);
    s1.insert(50);
    printSet(s1);

    // 指定排序规则，从大到小
    // 采用仿函数，修改排序规则
    set<int, MyCompare> s2;
    s2.insert(40);
    s2.insert(30);
    s2.insert(20);
    s2.insert(10);
    s2.insert(50);
    printSetPair(s2);
}

// 2.自定义数据类型
// 自定义数据类型，需要指定排序规则
void test02()
{
    set<Person, comparePerson> s1;
    Person p1("AA", 10);
    Person p2("BB", 20);
    Person p3("CC", 30);
    Person p4("DD", 140);
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);
    printSetPerson(s1);
}

int main()
{
    test01();
    test02();
    return 0;
}