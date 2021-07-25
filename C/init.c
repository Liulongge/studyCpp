// #include<stdio.h>

// int a;
// int *b;
// static float c;
// int main(void)
// {   
//     //     char str[200] = "Hello,World";
//     // char str2[] =  "Hello,World";
//     char d;
//     static char e;
//     static float f;
//     double *g;
//     static float c;
//     static int a;
//     printf("%d, %p, %f, %d, %d, %f, %p\n", a, b, c, d, e, f, g);
//     return 0;
// }

// #include<iostream>
// #include<cstring>
// using namespace std;
// char c;
// int main(void)
// {
//     char str[200] = "Hello,World";
//     char str2[] =  "Hello,World";
//     cout << sizeof(str) << "  " << strlen(str) << endl;      //200  11
//     cout << sizeof(str2) << "  " << strlen(str2) << endl;    //12   11
    
    
//  int a;
//     static float b;

//     printf("%d,%f,%d\n",a,b,c);
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
#include<string.h>
//using namespace std;

static int a=1;//全局初始化区 
int b=2;//全局初始化区 
char *p;//全局未初始化区 
char *p2;//全局未初始化区 
int *p3;//全局未初始化区 
int *p4;//全局未初始化区 
char *p5={"555555555"};//全局初始化区 

int main(){
    static int c=3;
    int d=4;//内存栈
    int e=7;//内存栈
    
    char *p6={"555555555"};
    p=(char*)malloc(sizeof(char)*10);//内存堆
    p2=(char*)malloc(sizeof(char)*10);//内存堆
    p3=(int*)malloc(sizeof(int));//内存堆
    p4=(int*)malloc(sizeof(int)*10);//内存堆
    for(int i=0;i<=9;i++)p4[i]=0x1;


    *p3=0x123;
    strcpy(p,"123456789");//文字常量区
    strcpy(p2,"987654321");
    strcpy(p2,"123456789");
    printf("123\n");
}