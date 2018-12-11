#include <stdio.h>
#include <string.h>

int main()
{
    char *p = "1111abc33333abc44444abc5555a";
    char *tmp = NULL;
    int i = 0;

    while (1)
    {
        tmp = strstr(p, "abc");
        if (tmp == NULL)
        {
            break;
        }
        else
        {
            ++i;
            // tmp 表示首地址
            p = tmp + strlen("abc");
        }
    }
    printf("i = %d\n", i);
    return 0;
}

