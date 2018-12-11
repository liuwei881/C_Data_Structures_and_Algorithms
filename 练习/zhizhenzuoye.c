#include <stdio.h>

int array()
{
	int a[] = {5, 100, 32, 45, 21, 67, 32, 68, 41, 99, 13, 71};
	int *p = &a[0];
	int i;
	int len = sizeof(a) / sizeof(*p);
	int maxvalue=0;
	int senvalue=0;
	
	for (i=0; i<len; ++i)
	{
		if (*(p + i) > maxvalue)
		{
			maxvalue = *(p + i);
		}
	}
	
	for (i=0; i<len; ++i)
	{
		if (*(p + i) == maxvalue)
		{
			continue;
		}
		else if (*(p + i) > senvalue)
		{
			senvalue = *(p + i);
		}
	}
	printf("%d ", senvalue);
	printf("\n");
	return 0;
}


int main()
{
	array();
	return 0;
}