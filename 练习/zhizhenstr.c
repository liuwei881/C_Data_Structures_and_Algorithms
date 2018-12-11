#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i=0; i<argc; ++i)
    {
        printf("test = %s\n", *(argv+i));
    }

    return 0;
}


int main01()
{
    char *p = "abc";
    int i;
    int len;
    len = sizeof(p)/ sizeof(*p);
    for (i=0; i<len; ++i)
    {
        printf("%c", *(p+i));
    }
    printf("\n");
    return 0;
}