#pragma once

#include<iostream>
#include<string>
using namespace std;

// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// 案例描述：实现一个通用数组类，要求如下

// 可以对内置数据类型以及自定义数据类型的数据进行存储
// 将数组中的数据存储到堆区
// 构造函数中可以传入数组的容量
// 提供对应的拷贝构造函数以及operator= 防止浅拷贝问题
// 提供尾插法和尾删除法对数组中的数据进行删减
// 可以通过下标的方式访问数组中的元素
// 可以获取数组中当前元素个数和数组的容量

template<typename T>
class MyArray
{
public:
    // 有参构造，参数，容量
    MyArray(int capacity)
    {
        cout << "MyArray 的有参构造" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];  // 开辟堆区数据
    }

    // 尾插法
    void Push_Back(const T &val)
    {
        // 判断容量是否等于大小
        if(this->m_Capacity == this->m_Size)
        {
            return;
        }
        // 在数组末尾插入数据
        this->pAddress[this->m_Size] = val;
        // 更新数组大小
        this->m_Size ++;
    }

    void Pop_back()
    {
        // 让用户访问不到最后一个元素，即尾删，逻辑删除
        if(this->m_Size ==0)
        {
            return;
        }
        this->m_Size--;
    }

    // 通过下标方式访问数组元素
    // 重载形式
    T &operator[](int index)
    {
        return this->pAddress[index];
    }

    // 返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 返回数组大小
    int getSize()
    {
        return this->m_Size;
    }

    ~MyArray()
    {
        cout << "MyArray 的析构" << endl;
        if(this->pAddress != nullptr)
        {
            // delete 数组
            delete[] this->pAddress;
            this->pAddress = nullptr;
        }
    }

    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        cout << "MyArray 的拷贝构造" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress = arr.pAddress;  // 浅拷贝

        // 深拷贝，重新在堆区开辟空间，同时将arr中数据拷贝
        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= 防止浅拷贝
    MyArray& operator=(const MyArray &arr)
    {
        cout << "MyArray 的operator=" << endl;
        // 先判断原来堆区是否有数据，有，先释放干净
        if(this->pAddress != nullptr)
        {
            delete[] this->pAddress;
            this->pAddress = nullptr;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

private:
    T *pAddress;
    int m_Capacity; // 数组容量
    int m_Size;     // 数组大小
};