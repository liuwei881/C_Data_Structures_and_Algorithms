#include <stdio.h>

//int a;
//
//int *func()
//{
//    return &a;
//}


int main()
{
//    int *p = NULL;
//
//    p = func();
//    *p = 100;
//
//    printf("a = %d\n", a);
    int i=0;
    char str[] = "nihaoma xiaogui";

    printf("str = %s\n", str);
    // 指针是指向数据元素的第一个元素
    printf("str[0] = %c\n", *str);

    while (*(str+i) != '\0')
    {
        printf("%c", *(str+i));
        ++i;
    }
    printf("\n");
    return 0;
}