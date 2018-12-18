#include <stdio.h>
#include <string.h>

void reverse(char s[], int n)
{
    int i;
    int j=n-1;
    char *p = &s[0];
    char d[1000];
    char *b = &d[0];

    for (i=0; i<n; ++i)
    {
        *(b+i) = *(p+j);
        --j;
    }

    for (i=0; i<n; ++i)
    {
        printf("%c", *b);
        ++b;
    }
    printf("\n");
}

int main()
{
    char s[10000];
    int n;
    while (1)
    {
        scanf("%s", s);
//    n = sizeof(s) / sizeof(*s);
        n = strlen(s);
        reverse(s, n);
    }
    return 0;
}