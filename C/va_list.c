

#include <stdarg.h> 
#include <stdio.h>

// int AveInt(int v,...);
 
//  void main()
// {
//    printf("%d\n",AveInt(2,2,3));
//    printf("%d\n",AveInt(4,2,4,6,8));
 
//    return;
// }
 
// int AveInt(int v,...)
// {
//    int ReturnValue=0;
//    int i = v;
 
//    va_list ap ;
//    va_start(ap,v);
//    printf("V: %d\n", v);
//    while(i>0)
//    {
//        ReturnValue += va_arg(ap, int);
//        i--;
//    }
//    va_end(ap); 
//    return ReturnValue /= v;
// }
#define ERR "ERROR"
#define LOG2(s) printf("[%s:%d] %s", __FILE__, __LINE__, s)
#define debug(format, ...) printf("Info:[%s:%s(%d)]:" format "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);


void sum(const char* grade,const char* file,const char* func, int line, const char* msg, ...)
{
    va_list vaList;                        //定义一个va_list型的变量

    char str[256] = {0};
    va_start(vaList, msg);
    vsprintf(str, msg, vaList);            //配合格式化字符串，输出可变参数
    va_end(vaList);
    printf("%s: ", grade);
    printf("%s->", file);
    printf("%s", func);
    printf("(%d): ", line);
    printf("%s", str);


    va_start(vaList, msg);                 //va_start初始化vaList
    int first = va_arg(vaList, int);       //va_arg获取第一个参数
    char* second = va_arg(vaList, char*);  //va_arg获取第二个参数
    int third = va_arg(vaList, int);       //va_arg获取第三个参数
    printf("%s, %d, %s, %d\n",msg, first, second, third);
    va_end(vaList);                        //va_end结束vaList，将vaList置NULL

    return;
}

#define PRINTF(grade,format, ...) do{sum(grade,__FILE__,__FUNCTION__,__LINE__,format, ##__VA_ARGS__);} while(0)

 int main()
 {   
     LOG2("H\n");
     PRINTF(ERR,"hello world %d %s %d\n", 9, "666", 3);
     debug(ERR,"hello world %d %s %d", 9, "666", 3);
     return 0;
 }

