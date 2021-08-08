#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 容器的基本概念
// 功能
// vector 数据结构和数组非常类似，也称为 单端数组

// vector 与 普通数组区别
// 不同之处在于数组是静态空间，而vector可以动态扩展

// 动态扩展：
// 1.并不是在原始空间之后续接新空间，而是找到更大的内存空间，然后将原始数据拷贝新空间，释放原空间
// 2.vector 容器的迭代器是 支持随机访问 的迭代器

// vector 容量和大小
// 功能描述：对vector容器的容量和大小操作

// 函数原型
// empty();                     判断容器是否为空
// capacity();                  容器的容量
// size();                      返回容器中元素的个数
// resize(int num);             重新指定容器的长度为num，若容器变长，则以默认值填充新位置
//                                                   若容器变短，则末尾超出容器长度的元素被删除
// resize(int num, elem);       重新指定容器的长度为num，若容器变长，则以elem填充新位置
//                                                   若容器变短，则末尾超出容器长度的元素被删除

// 总结：
// 判断是否为空   empty
// 返回元素个数   size
// 返回容器容量   capacity
// 重新指定大小   resize

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 为真 代表为 空
    if(v1.empty())
    {
        cout << "v1 为空" << endl;
    }
    else
    {
        cout << "v1 不为空" << endl;
        cout << "v1 的容量为" << v1.capacity() << endl;
        cout << "v1 的大小为" << v1.size() << endl;
    }

    // 重新指定大小,如果指定的比原来长了，超出部分会被默认（指定）值填充
    v1.resize(20);       // 默认值填充
    // v1.resize(20, 6); // 指定值填充
    printVector(v1);
    if(v1.empty())
    {
        cout << "v1 为空" << endl;
    }
    else
    {
        cout << "v1 不为空" << endl;
        cout << "v1 的容量为" << v1.capacity() << endl;
        cout << "v1 的大小为" << v1.size() << endl;
    }
    
    // 重新指定大小，如果指定的比原来短了，超出部分会删除掉
    v1.resize(5);
    printVector(v1);
    if(v1.empty())
    {
        cout << "v1 为空" << endl;
    }
    else
    {
        cout << "v1 不为空" << endl;
        cout << "v1 的容量为" << v1.capacity() << endl;
        cout << "v1 的大小为" << v1.size() << endl;
    }
}

int main()
{
    test01();
    return 0;
}