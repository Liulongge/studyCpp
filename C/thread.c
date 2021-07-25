//gcc thread.c -o thread -lpthread 
#include <unistd.h>  
#include <pthread.h> 
#include<stdio.h> 
#include<sys/types.h>
#include <sys/syscall.h>

pid_t gettid() 
{
	return syscall(__NR_gettid); 
}

void* thread_func1(void *arg) 
{
	while(1)
	{
		printf("run func1\n");
		sleep(1);
		printf("thread func1 tid: %d\n", gettid());
	}
	return 0;
}
void* thread_func2(void *arg) 
{
	while(1)
	{
		printf("run func2\n");
		sleep(1);
		printf("thread func2 tid: %d\n", gettid());
	}
	return 0;
}
int main()
{
	pthread_t thread1,thread2=0;
	int i = 0;
	printf("process pid: %d\n", getpid());
	pthread_create(&thread1, NULL, thread_func1, NULL);	
	pthread_create(&thread2, NULL, thread_func2, NULL);	
	while(1)
	{
		sleep(1);
		printf("Process sleep 1 s\n");
	}
	return 0;
}