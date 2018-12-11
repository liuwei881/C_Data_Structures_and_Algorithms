#include <stdio.h>

int IsEven(int n)
{
    if (0 == n % 2)
    {
        return 1;
    }
    return 0;
}

long int Pow( long int X, unsigned int N)
{
    if (N == 0)
    {
        return 1;
    }
    if (N == 1)
    {
        return X;
    }
    if (IsEven(N))
    {
        return Pow( X*X, N/2);
    }
    else
    {
        return Pow(X*X, N/2) * X;
    }
}

int main()
{
    int r;
    r = Pow(2, 10);
    printf("%d\n", r);
}