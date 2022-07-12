// g++ 8_vectorOperterUsed.cpp -o demo

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 1、删除数据
// 删除前 n 个数据
// 删除后 n 个数据
void deleteData(void)
{
    const int lenth = 20;
    //产生20个元素
    vector<int> mVec;
    for(int i = 0; i< lenth; i++)
    {
       mVec.push_back(i);
    }
    // 打印原始vector
    cout << "原始数据: " << endl;
    printVector(mVec);

    //删除前5个元素
    cout << "删除前 5 个数据: " << endl;
    for(vector<int>::iterator iter = mVec.begin(); mVec.size() > lenth - 5; )
    {
        iter = mVec.erase(iter);
    }
    printVector(mVec);

    cout << "删除后 5 个数据: " << endl;
    while(mVec.size() > lenth - 5 - 5)
    {
        mVec.pop_back();
    }
    printVector(mVec);
}

// 2、数据排序
// 升序
// 降序

bool ascendingSort(int a, int b)
{
    return a < b;
}

bool descendingSort(int a, int b)
{
    return a > b;
}

void dataSort(void)
{
    const int lenth = 10;
    //产生20个元素
    vector<int> mVec;
    for(int i = 0; i< lenth; i++)
    {
       mVec.push_back(rand() % 1000);
    }
    cout << "原始数据: " << endl;
    printVector(mVec);

    cout << "升序排序: " << endl;
    sort(mVec.begin(), mVec.end(), ascendingSort);
    printVector(mVec);

    cout << "降序排序: " << endl;
    sort(mVec.begin(), mVec.end(), descendingSort);
    printVector(mVec);

}

int main()
{
    cout << "\n====== 删除数据 ====== " << endl;
    deleteData();

    cout << "\n====== 数据排序 ====== " << endl;
    dataSort();
    return 0;
}