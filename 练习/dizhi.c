#include <stdio.h>

int func()
{
	int a;
	
	return &a;
}

int main()
{
	int *p = NULL;
	//linux 64位中c语言函数执行完后, 内存就释放了。所以 *p 指向的内存不可用了
	p = func();
	*p = 100;
	
	return 0;
}