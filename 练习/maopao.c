#include <stdio.h>

int main()
{
	int a[] = {2, 3, 5, 6, 8, 10, 1, 100, -1, -2, -100, 98, 56, -23};
	int temp;
	int i;
	int j;
	int n;
	/*计算数组元素的大小*/
	n = sizeof(a)/sizeof(a[0]);
	
	printf("冒泡排序前:");
	for(i=0;i<n;i++)
	{
		printf("%d,", a[i]);
	}
	printf("\n");
	
	/*冒泡排序最差时间O(n^2)*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("冒泡排序后:");
	for(i=0;i<n;i++)
	{
		printf("%d,", a[i]);
	}
	printf("\n");
}