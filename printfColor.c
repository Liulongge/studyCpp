#include <stdio.h>  
#define BACK_GROUND_BLACK 40
#define BACK_GROUND_RED 41
#define BACK_GROUND_GREEN 42
#define BACK_GROUND_YELLOW 43
#define BACK_GROUND_BLUE 44
#define BACK_GROUND_PURPLE 45
#define BACK_GROUND_DARK_GREEN 46
#define BACK_GROUND_WHITE 47

#define FONT_COLOR_BLACK 30
#define FONT_COLOR_RED 31
#define FONT_COLOR_GREEN 32
#define FONT_COLOR_YELLOW 33
#define FONT_COLOR_BLUE 34
#define FONT_COLOR_PURPLR 35
#define FONT_COLOR_DARK_GREEN 36
#define FONT_COLOR_DARK_WHITE 37


int main(void)  
{  
  
    printf("\033[40;37m black-----write \033[0m\n");  
    printf("\033[41;36m red--dark_green \033[0m\n"); 
    printf("\033[42;35m green----purple \033[0m\n"); 
    printf("\033[43;34m yellow-----blue \033[0m\n"); 
    printf("\033[44;33m blue-----yellow \033[0m\n"); 
    printf("\033[45;32m purple----green \033[0m\n"); 
    printf("\033[46;31m dark_green--red \033[0m\n"); 
    printf("\033[47;30m white-----black \033[0m\n"); 
    printf("\033[47;30m\033[1m white-----black(bold_highlight) \033[0m\n"); 
    printf("\033[47;30m\033[2m white-----black(dim) \033[0m\n"); 
    printf("\033[47;30m\033[3m white-----black(italics) \033[0m\n");
    printf("\033[47;30m\033[4m white-----black(underline) \033[0m\n"); 
    printf("\033[47;30m\033[5m white-----black(twinkle) \033[0m\n");  
    printf("\033[47;30m\033[7m white-----black(reversal) \033[0m\n");  
    printf("\033[47;30m\033[8m white-----black(hide) \033[0m\n");    
    return 0;  
} 