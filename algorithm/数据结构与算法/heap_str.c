#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char * a1 = NULL;
    char * a2 = NULL;
    a1 = (char *)malloc(9 * sizeof(char));
    strcpy(a1, "data.bian"); //将字符串"data.bian"复制给a1
    a2 = (char *)malloc(9 * sizeof(char));
    strcpy(a2, "cheng.net");
    int lengthA1 = strlen(a1); //a1串的长度
    int lengthA2 = strlen(a2); //a2串的长度
    //尝试将合并的串存储在 a1 中，如果 a1 空间不够，则用realloc动态申请
    if(lengthA1 < lengthA1 + lengthA2){
        a1 = (char *)realloc(a1, (lengthA1 + lengthA2) * sizeof(char));
    }
    //合并两个串到a1中
    for(int i=lengthA1; i<lengthA1+lengthA2; i++){
        a1[i] = a2[i-lengthA1];
    }
    printf("%s\n", a1);
    //用完要释放
    free(a1);
    free(a2);
    return 0;
}

