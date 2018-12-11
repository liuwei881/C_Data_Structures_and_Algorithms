#include <stdio.h>

int main()
{
	int *p[3];
	int a[3] = {0, 1, 2};
	int i;
	int len;
	len = sizeof(p) / sizeof(p[0]);
	
	for (i=0; i<len; ++i)
	{
		p[i] = &a[i];
	}
	
	for (i=0; i<len; ++i)
	{
		printf("%d ", *p[i]);
	}
	printf("\n");
	return 0;
}