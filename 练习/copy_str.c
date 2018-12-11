#include <stdio.h>
#include <string.h>

int main()
{
	char src[100] = "hello";
	char *p = &src[0];
	char dst[100];
	char *b = &dst[0];
	int i;
	int len;
	
	len = strlen(src);
	for (i=0; i<len; ++i)
	{
		*(b+i) = *(p+i);
	}
	
	for (i=0; i<len; ++i)
	{
		printf("%c", *b);
		++b;
	}
	printf("\n");
	return 0;
}