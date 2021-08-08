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

// vector 插入与删除
// 功能描述：对vector 容器进行插入、删除操作

// 函数原型：
// push_back(el1);                                      尾部插入元素
// pop_back();                                          删除最后一个元素
// insert(const_iterator pos, ele);                     迭代器指向位置 pos 插入元素 els
// insert(const_iterator pos, int count, ele);          迭代器指向位置 pos 插入 count 个元素 ele
// erase(const_iterator pos);                           删除迭代器指向的元素
// erase(const_iterator start, const_iterator end);     删除迭代器从 start 到 end 之间的元素
// clear();                                             删除容器中所有元素

// 总结
// 尾插 push_back
// 尾删 pop_back
// 插入 insert (位置迭代器)
// 删除 erase  (位置迭代器)
// 清空 clear

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
    // 尾插法
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    printVector(v1);

    // 尾删
    v1.pop_back();
    printVector(v1);

    // 插入
    v1.insert(v1.begin(), 100); // 第一个参数是迭代器
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除
    v1.erase(v1.begin());
    printVector(v1);

    // v1.erase(v1.begin(), v1.end());  // 从头删到尾
    // printVector(v1);

    // 全部删除
    v1.clear();      
    printVector(v1);
}

int main()
{
    test01();
    return 0;
}