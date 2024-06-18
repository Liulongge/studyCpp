// gcc -S 00-if.c
#include <stdio.h>  
  
int main(int argc, char *argv[])
{  
    char number = *argv[0]; // 你可以改变这个值进行测试  
  
    if (number == 1)
    {  
        printf("Number is 1\n");  
    }
    else if (number == 2)
    {  
        printf("Number is 2\n");  
    }
    else if (number == 3)
    {  
        printf("Number is 3\n");  
    }
    else
    {  
        printf("Number is not 1, 2, or 3\n");  
    }  
  
    return 0;  
}