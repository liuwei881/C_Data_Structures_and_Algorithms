#include <stdio.h>

void swap(int *m, int *n)
{
	int tmp;
	
	tmp = *m;
	*m = *n;
	*n = tmp;
	printf("a=%d, b=%d\n", *m, *n);
}

// 数组作为函数的参数, int a[] 只是 int *a, 32位占4字节, 64位占8字节
void print_array(int a[], int n)
{
	int i;
	for (i=0; i<n; ++i)
	{
		printf("%d ", *(a+i));
	}
	printf("\n");
}


int main()
{
	int a[] = {1, -1, 5, 12, -2, 4, -4};
	
	// a = 15;
	// b = 34;
	// swap(&a, &b);
	int n = sizeof(a) / sizeof(*a);
	print_array(a, n);
	return 0;
}