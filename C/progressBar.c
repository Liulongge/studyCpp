#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BAR_SIZE 100

void progressbar(int sec)
{
    char bar[BAR_SIZE+1] = {0}; /* '\0' */
    char ret[5]={"/|-\\"};
    for(int j = 1; j <= BAR_SIZE; j++) 
    {
        memset(bar, ' ', BAR_SIZE);
        memset(bar, '>', j);
        // \033[33m .... \033[0m代表进度条显示为黄色
        // - 代表左对齐
        printf("\033[33m[%-s]%3d%%[%c]\033[0m", bar, j, ret[j%4]);

        // printf("[%-101s][%d%%]\r",buff,i);
        fflush(stdout);
        usleep(sec*1000*100);
      	/* 33[1K代表清行，33[110D代表光标左移110字符。 */
        printf("\033[1K\033[110D"); ///< 光标回到行首
    }
    printf("\033[32m process done !!!\n\033[0m"); ///< 光标回到行首
}

int main(void)
{
    progressbar(1);
}