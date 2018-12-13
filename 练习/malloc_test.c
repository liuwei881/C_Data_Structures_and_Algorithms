#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    //p指向堆区内存
    p = (int *)malloc(sizeof(p));
    *p = 10;
    printf("*p = %d\n", *p);
    //使用完要释放
    free(p);
    return 0;
}
