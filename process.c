//indent -kr -i8 studyCpp/dir.c

#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include<unistd.h>
#include <string.h>


int main(void)
{
    int num = 0;
	while(1)
    {

        sleep(5);
        num++;
        printf("sleep %d!\n",num);
    }
	
	

	return 0;

}
