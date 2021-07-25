//indent -kr -i8 studyCpp/dir.c

#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include<unistd.h>
#include <string.h>


int main(void)
{
	char command[512] = { 0 };
	char path[256] = "../testDir/dir7";
	if (access(path, F_OK)) {
		printf("%s DOESN'T EXISIT!\n", path);
		snprintf(command, 512, "mkdir -p %s\n", path);
		system(command);
		if (access(path, F_OK) ==0) {
			printf("%s creat success!\n", path);
		}

	} else {
		printf("%s EXISIT!\n", path);
	}

	return 0;

}
