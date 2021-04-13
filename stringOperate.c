// gcc stringOperate.c -o stringOperate
#include <stdio.h>
#include <string.h>
 
int main()
{
    char src[40];
    char dest[20];
    // 初始化字符串
    memset(dest, '\0', sizeof(dest));
    // 字符串赋值
    // #include <string.h>
    // C 库函数 char *strcpy(char *dest, const char *src) 把 src 所指向的字符串复制到 dest。
    //需要注意的是如果目标数组 dest 不够大，而源字符串的长度又太长，可能会造成缓冲溢出的情况
    strcpy(src, "Hello World. I'm iron man!");
    
    // 字符串剪切（拷贝）
    // #include <string.h>
    // C 库函数 char *strncpy(char *dest, const char *src, size_t n) 
    // 把 src 所指向的字符串复制到 dest，最多复制 n 个字符。当 src 的长度小于 n 时，dest 的剩余部分将用空字节填充。
    strncpy(dest, src, 12);
    // Hello World.
    printf("最终的目标字符串： %s\n", dest);
    
    strcpy(src, "Hello");

    strcat(src, " World.");
    printf("最终的目标字符串： %s\n", src);

    memset(src, '\0', sizeof(dest));
    strcpy(src, "Hello");
    strncat(src, " World. I love you!", 7);
    printf("最终的目标字符串： %s\n", src);


    memset(dest, '\0', sizeof(dest));
    strcpy(src, "Hello");
    snprintf(dest, sizeof(src), "%s--%s", src, "World.");
    printf("最终的目标字符串： %s\n", dest);

    // 字符串分解
    // C 库函数 char *strtok(char *str, const char *delim) 分解字符串 str 为一组字符串，delim 为分隔符。
    char str[80] = "This is-www.studyCpp.com-website";
    const char s[2] = "-";
    char *token;
    /* 获取第一个子字符串 */
    token = strtok(str, s);
    /* 继续获取其他的子字符串 */
    while( token != NULL ) 
    {
       printf( "%s\n", token );
       token = strtok(NULL, s);
    }
    // This is
    // www.studyCpp.com
    // website

   return(0);
}