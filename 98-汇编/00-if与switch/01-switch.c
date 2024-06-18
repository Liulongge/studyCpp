#include <stdio.h>  
  
int main(int argc, char *argv[])
{  
    char number = *argv[0]; // 你可以改变这个值进行测试  
  
    switch (number)
    {  
        case 1:  
            printf("Number is 1\n");  
            break;  
        case 2:  
            printf("Number is 2\n");  
            break;  
        case 3:  
            printf("Number is 3\n");  
            break;  
        default:  
            printf("Number is not 1, 2, or 3\n");  
            break;  
    }  
  
    return 0;  
}