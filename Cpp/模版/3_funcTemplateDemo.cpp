#include<iostream>

using namespace std;
// 模板特点
// 模板不可以直接使用，他只是一个框架
// 模板的通用并不是万能的

// C++另一种编程思想就是 泛型编程 ，主要利用的技术的 模板
// C++提供两种模板机制：1.函数模板、2.类模板

// 注意事项
// 自动推类型推导，必须推导出一致的数据类型 T 才可以使用
// 摸版必须要确定出 T 的数据类型，才可以使用

// 案例描述：
// 利用函数模板封装一个排序函数，可以对不同数据类型进行排序
// 排序规则从大到小，排序算法为选择排序
// 分别利用 char数组 和 int数组 进行测试

// 交换函数模板
template<class T>
void mySwap(T&a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 排序算法
template<typename T>
void mySort(T arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        int max = i;
        for(int j = i + 1; j < len; j++)
        // 认定最大值比遍历出的数值小，说明j下标的最大值
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if(max != i)
        {
            // 交换max和i元素
            mySwap(arr[max], arr[i]);
        }
    }
}

// 打印数组的模板
template<class T>
void printArray(T arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    // 测试char数组
    char charArr[] = "badcfe";
    int num = sizeof(charArr);
    mySort(charArr, num);
    printArray(charArr, num);
}

int main()
{
    test01();


    return 0;
}