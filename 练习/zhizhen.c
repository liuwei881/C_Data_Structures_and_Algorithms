#include <stdio.h>


int main()
{
	int a=10;
	int * p;
	
	p = &a;
	printf("p = %p, a = %p\n", p, &a);
	
	* p = 100;
	printf("p = %d, a = %d, &a = %p\n", *p, a, &a);
	
	return 0;
}