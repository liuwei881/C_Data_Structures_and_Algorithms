#include <stdio.h>

int main()
{
	int n = 1;
	int num = 0;
    for(n=1;n<=100;++n)
	{
		num += n;
	}
	printf("1+2+3+4....99+100 = %d\n", num);

    return 0;
}