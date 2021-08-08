#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// stl的诞生
// 长久以来，软件界一直希望建立一种可以重复利用的东西
// C++面向对象和范式编程思想，目的就是复用性的提升
// 大多情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
// 为了建立数据结构和算法的一套标准，诞生了STL

// 容器中嵌套容器，将所有数据进行遍历输出

void test01()
{
    vector< vector<int> > v;

    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 向小容器中添加数据
    for(int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // 将小容器插入到大的容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器，把所有数据遍历一遍
    for(vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it) 是一个容器，为 vector<int>
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }

}
int main()
{
    test01();
    return 0;
}