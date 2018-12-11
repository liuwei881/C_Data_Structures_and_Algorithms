#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[] = "abceadc,bcd,e,yes,ert,uio,qwer";
	char *p;
	int j;
	int b = 10;
	char str[100];
	char f[] = "1232";
	p = strtok(a, ",");
	while (p = strtok(NULL, ","))
	{
		printf("%s ", p);
	}
	printf("\n");
	j = atoi(f);
	printf("j = %d\n", j);
	
	sprintf(str, "%d", b);
	printf("str = %s\n", str);
	return 0;
}