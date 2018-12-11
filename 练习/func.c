#include <stdio.h>

void fun()
{
	int a = 2, b = 5;
	printf("我是无返回值无参数的函数\n");
	printf("a + b = %d\n", a+b);
}

int main()
{
	fun();
	return 0;
}