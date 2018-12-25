#include<stdio.h>

int repeatedNTimes(int *p, int len){
    int i=0;
    for(i; i<len;i++){
        for(int j=i+1; j<len; j++){
            if(*(p+i)==*(p+j)){
                return *(p+j);
            }
        }
    }
    return 0;
}

int main(){
    int A[]={12,62,62,30,62,96,97,62,62,6,73,62,62,5,62,8,64,62,18,62};
    int len;
    int *p;
    p=A;
    len= sizeof(A) / sizeof(int);
    printf("%d", repeatedNTimes(p, len));
    return 0;
}



