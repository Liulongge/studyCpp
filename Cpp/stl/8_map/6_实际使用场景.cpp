#include<iostream>
#include<map>
#include<string>

using namespace std;

// 1、保护：key值不存在下的保护
void printMap(const map<string, int> &s)
{
    // 只读迭代器 consy_iterator
    for(map<string, int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "key: " << it->first << ", value: " << it->second << " " << endl;
    }
    cout << endl;
}

void test01()
{
    // 默认构造
    map<string, int> m;
    m.insert(pair<string, int>("a", 10));
    m.insert(pair<string, int>("b", 30));
    m.insert(pair<string, int>("c", 20));
    m.insert(pair<string, int>("d", 40));
    printMap(m);
    map<string, int>::iterator iter = m.find("f");
    if(iter == m.end())
    {
        cout << "对迭代器做保护" << endl;
        cout << "找不到 key: 'f' !" << endl;
    }

    iter = m.find("b");
    if(iter != m.end())
    {
        cout << "找到了 key: 'b', 值为: " << iter->second << endl;
    }
}

int main()
{
    test01();
    return 0;
}