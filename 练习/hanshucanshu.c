#include <stdio.h>

void func(int a)
{
	printf("a = %d\n", a);
}

void func2(int a, char str, char s[100])
{
	printf("a = %d, str = %c, s[100] = %s\n", a, str, s);
}

int main()
{
	func(5);
	func2(10, 'c', "erta");
	
	printf("$$\b$$ = %d\n", '\b');
	return 0;
}