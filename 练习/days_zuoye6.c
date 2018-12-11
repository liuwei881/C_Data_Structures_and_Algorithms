#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
	int i;
	int j;
	int num;
	int num_array[4];
	int d[4];
	int n;
	srand((unsigned int)time(NULL));
	num = rand() % 9000 + 1000;
	/*随机千位数*/
	num_array[0] = num/1000;
	/*随机百位数*/
	num_array[1] = num%1000/100;
	/*随机十位数*/
	num_array[2] = ((num%1000)%100)/10;
	/*随机个位数*/
	num_array[3] = num%1000%100%10;
	while(1)
	{
		printf("请输入一个四位的整形它会与系统产生的进行比较\n");
		scanf("%d", &i);
		/*千位数*/
		d[0] = i/1000;
		/*百位数*/
		d[1] = (i%1000)/100;
		/*十位数*/
		d[2] = ((i%1000)%100)/10;
		/*个位数*/
		d[3] = i%1000%100%10;
		n = 0;
		for(j=0;j<4;j++)
		{
			if(d[j] > num_array[j])
			{
				printf("第%d位数大了\n", j+1);
			}
			else if(d[j] < num_array[j])
			{
				printf("第%d位数小了\n", j+1);
			}
			else
			{
				printf("第%d位相等\n", j+1);
				++n;
			};
		};
		if(4==n)
		{
			printf("相等了数字为: %d\n", num);
		};
	};
	/*
	while(i != 0)
    {
        i /= 10;
        ++count;
    };
	if(4 == count)
	{
		while(num != i)
		{
			if(num/1000 > i/1000)
			{
				printf("输入的千位数小了\n");
			}else if(num/1000 < i/1000)
			{
				printf("输入的千位数大了\n");
			}else{
				printf("输入的千位数相等\n");
			};
			if((num%1000)/100 > (i%1000)/100)
			{
				printf("输入的百位数小了\n");
			}else if((num%1000)/100 < (i%1000)/100)
			{
				printf("输入的百位数大了\n");
			}else{
				printf("输入的百位数相等\n");
			};
			if(((num%1000)%100)/10 > ((i%1000)%100)/10)
			{
				printf("输入的十位数小了\n");
			}else if(((num%1000)%100)/10 < ((i%1000)%100)/10)
			{
				printf("输入的十位数大了\n");
			}else{
				printf("输入的十位数相等\n");
			};
			if(num%1000%100%10 > i%1000%100%10)
			{
				printf("输入的个位数小了\n");
			}else if(num%1000%100%10 < i%1000%100%10)
			{
				printf("输入的个位数大了\n");
			}else{
				printf("输入的个位数相等\n");
			};
			printf("请继续输入四位数字: ");
			scanf("%d", &i);
		};
		printf("系统的数字为: %d\n输入的数字为: %d\n", num, i);
	}else{
		printf("请输入一个四位的整形数字\n");
		sleep(2);
	};
	*/
		
	return 0;
}