//gcc predefChar.c -o  function
#include <stdio.h>
#include <string.h>

void subFunc3(const char *func_name)
{
    printf("function \"%s\" call me(%s)\n", func_name, __FUNCTION__);
}

void subFunc2(const char *func_name)
{
    printf("function \"%s\" call me(%s)\n", func_name, __FUNCTION__);
    subFunc3(__FUNCTION__);
}

void subFunc1(const char *func_name)
{
    printf("function \"%s\" call me(%s)\n", func_name, __FUNCTION__);
    subFunc2(__FUNCTION__);
}
int main()
{
    printf("function name: %s, function file: %s, function line: %d\n",  __FUNCTION__, __FILE__, __LINE__);
    printf("File = %s\nLine = %d\nFunc=%s\nDate=%s\nTime=%s\n", 
        __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__);
    subFunc1(__FUNCTION__);
    return(0);
}