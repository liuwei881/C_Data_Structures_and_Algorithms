#include <stdio.h>

int main()
{
    char b[] = "hello";
    char *p = &b[0];

    *p = '1';
    ++p;
    *p = '2';
    printf("%s\n", b);
    printf("%s\n", p-1);
    printf("%c\n", *p);
    return 0;
}