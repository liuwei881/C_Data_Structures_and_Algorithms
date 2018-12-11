#include <stdio.h>

int main01()
{
    int s[10];
    int lim=8;
    int i;
    char c;

    for (i=0; i<lim-1; ++i)
    {
        if (c=getchar() != '\n')
        {
            c != EOF;
            s[i] = c;
        }
    }
    return 0;
}


#define MAX_STRING_LENGTH 100

int main(void) {
/*
for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
s[i] = c;
*/
    int i = 0,
    lim = MAX_STRING_LENGTH;
    char s[MAX_STRING_LENGTH];
    while (i < (lim - 1)) {
        c = getchar();
        if (c == EOF)
            break;
        else if (c == '\n')
            break;
        s[i++] = c;
    }
    s[i] = '\0'; /* terminate the string */
    return 0;
}