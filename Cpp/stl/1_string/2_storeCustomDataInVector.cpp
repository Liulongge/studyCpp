#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// stl的诞生
// 长久以来，软件界一直希望建立一种可以重复利用的东西
// C++面向对象和范式编程思想，目的就是复用性的提升
// 大多情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
// 为了建立数据结构和算法的一套标准，诞生了STL

// vector中存放自定义数据类型，并打印输出
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

void test01()
{
    vector<Person> v;
    Person p1("A", 10);
    Person p2("B", 11);
    Person p3("C", 12);
    Person p4("D", 13);
    Person p5("E", 14);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    // 遍历容器中的数据
    // 把 it 当做指针， *it 解引用出来的是 Person 数据类型
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << "name: " << (*it).m_Name << ", age: " <<  (*it).m_Age << endl;
        cout << "name: " << it->m_Name << ", age: " <<  it->m_Age << endl;
    }
}

// 存放自定义数据类型的指针
void test02()
{
    vector<Person *> v;
    Person p1("A", 10);
    Person p2("B", 11);
    Person p3("C", 12);
    Person p4("D", 13);
    Person p5("E", 14);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    // 遍历容器中的数据
    // 把 it 当做指针， *it 解引用出来的是 Person * 数据类型
    // ->   等价于    *(*it).
    for(vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << "name: " << (*(*it)).m_Name << ", age: " <<  (*(*it)).m_Age << endl;
        cout << "name: " << (*it)->m_Name << ", age: " <<  (*it)->m_Age << endl;
    }
}

int main()
{
    cout << "存放用户数据类型：" << endl;
    test01();
    cout << "存放用户数据类型指针：" << endl;
    test02();
    return 0;
}