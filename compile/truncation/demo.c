#include <stdio.h>
 
int main(void)
{
	u_int64_t a = func1();
	printf("\033[33m 使用隐式函数声明，编译器默认会将函数返回值声明为 int, 在64位系统中，int位32位 \033[0m\n");
	printf("\033[33m 对于64位数据，采用隐式函数声明，则会造成数据截断 64 -> 32，数据会产生高位截断 \033[0m\n");
	printf("数据溢出：%lld\n",a);

	u_int64_t b = func2();
	printf("输出未溢出：%lld\n",b);
	return 0;
}
