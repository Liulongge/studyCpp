#include<stdio.h>
#include<stdlib.h>

uint64_t func1()
{
	return 2147483648; // 2^31
}

uint64_t func2()
{
	return 2147483648 -1; // 2^31 - 1
}