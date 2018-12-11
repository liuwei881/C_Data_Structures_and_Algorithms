#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "abcdef";
	char *p;
	p = strchr(a, 'c');
	//p = strstr(a, "cde");
	if (p == NULL)
	{
		printf("没有找到");
	}
	else{
		printf("找到了: %s\n", p);
	}
	return 0;
}
