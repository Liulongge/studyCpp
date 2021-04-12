// g++ callBack.cpp -o callBack

#include <stdio.h>
#include <stdlib.h>                                                                 
 
// 定义函数
int myAdd(int a, int b) { return a + b; }
int mySub(int a, int b) { return a - b; }
int myMul(int a, int b) { return a * b; }
int myDiv(int a, int b) { return a / b; }

// 函数指针
// int Func(int x);   /*声明一个函数*/
// int (*p) (int x);  /*定义一个函数指针*/
// p = Func;          /*将Func函数的首地址赋给指针变量p*/

// 使用 typedef 简化一些比较复杂的类型声明
// typedef void (*pCallBackFunc)(char* pMsg, unsigned int nMsgLen);
// registerCallbackFunc(const string& strKey, pCallBackFunc CallbackFunc, bool flag);

typedef int (*fcb_func)(int a, int b);
int (*fcb_func2)(int a, int b);

typedef struct
{
    int a, b; 
    fcb_func fcb; /* 函数管理器 */
} mydata_t;

mydata_t data = { 0 };
int result = 0;

// 定义操作
void myOperate(mydata_t *data)
{
    int c = data->fcb(data->a, data->b);
    printf("mydata callback operate result %d\n", c);
}
 
int main()
{
    data.a = 9;
    data.b = 3;
    
    // 将函数myAdd首地址传递给指针变量
    data.fcb = myAdd;
    myOperate(&data);

    data.fcb = mySub;
    result = data.fcb(data.a, data.b);
    printf("mydata callback operate result %d\n", result);

    data.fcb = myMul;
    mydata_t *data_ptr = &data;
    result = data_ptr->fcb(data_ptr->a, data_ptr->b);
    printf("mydata callback operate result %d\n", result);

    fcb_func2 = myDiv;
    result = fcb_func2(data_ptr->a, data_ptr->b);
    printf("mydata callback operate result %d\n", result);

    return 0;
}