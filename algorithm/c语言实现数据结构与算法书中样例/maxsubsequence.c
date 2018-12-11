#include <stdio.h>


int MaxSubsequenceSum( const int A[], int N)
{
	int ThisSum, MaxSum, i, j, k;
	
	/* 1*/
	MaxSum = 0;
	//2
	for (i=0; i<N; i++)
	{
		//3
		for (j=i; j<N; j++)
		{
			//4
			ThisSum = 0;
			//5
			for (k=i; k<=j; k++)
			{
				//6
				ThisSum += A[k];
			}
			//7
			if (ThisSum > MaxSum)
			{
				//8
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum; //9
}