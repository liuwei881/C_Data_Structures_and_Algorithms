#include <stdio.h>

int main()
{
	int sum;
	int i;
	int j;
	int a[5][10];
	/* 一共有 5 * int[10] = 5 * 4 * 10 = 200空间*/
	/*打印行数*/
	printf("打印多元数组的行数: %lu\n", sizeof(a)/sizeof(a[0]));
	/*打印列数*/
	printf("打印多元数组的列数: %lu\n", sizeof(a[0])/sizeof(int));
	/*打印总元素的大小*/
	printf("打印总元素的大小: %lu\n", sizeof(a)/sizeof(int));
	
	int b[5][3] = 
	{
		{10, 20, 30},
		{45, 12, 13},
		{20, 12, 34},
		{34, 45, 56},
		{56, 78, 23}
	};
	
	for(i=0;i<3;i++)
	{
		sum = 0;
		for(j=0;j<5;j++)
		{
			sum += b[j][i];
		};
		printf("数组 %d 列和为: %d\n", i, sum);
	};
	return 0;
}