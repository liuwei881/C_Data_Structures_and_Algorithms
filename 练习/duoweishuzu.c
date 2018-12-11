#include<stdio.h>

int main()
{
	int i;
	int j;
	int num = 0;
	int a[3][4];
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j] = num;
			num++;
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d, ", a[i][j]);
		}
		printf("\n");
	}
}