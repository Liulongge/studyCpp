#include <stdio.h>

// 查看数据类型
// c11新特性
#define gettype(X) _Generic((X), \
        u_int8_t: "u_int8_t", \
        char: "char", \
        int: "int", \
        float: "float", \
        double: "double", \
        default: "other")

int main(){
    // typedef enum { Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } day;

    // 定义枚举类型
    // 枚举类型默认为 int型
    // 此处定义枚举类型为 uint8
    enum day:u_int8_t
    { 
        Mon = 1, 
        Tues, 
        Wed, 
        Thurs, 
        Fri, 
        Sat, 
        Sun 
    } day;

    printf("Mon值为：%d\n", Mon);
    printf("Mon数据类型为：%s\n", gettype(Mon));
    // printf("%d\n", typeof(Mon));
    return 0;
}