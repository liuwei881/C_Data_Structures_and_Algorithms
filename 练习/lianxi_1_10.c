#include <stdio.h>

int main()
{
	int c;
	int inspace;
	
	inspace = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			putchar('\\');
			putchar('t');
			inspace = 1;
		}
		if (c == '\b')
		{
			putchar('\\');
			putchar('b');
			inspace = 1;
		}
		if (c == '\\')
		{
			putchar('\\');
			inspace = 1;
		}
		if (0 == inspace)
		{
			putchar(c);
		}
	}
	return 0;
}