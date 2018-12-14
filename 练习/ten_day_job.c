#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_abc();
void getchar_abc();
int compare();

char a[100];
char b[100];

int main(){
    int i;
    time_t t_start;
    time_t t_end;
    rand_abc();
    t_start = time(NULL);
    getchar_abc();
    compare();
    t_end	= time(NULL);
    printf("所用的时间为: %.2fs\n", difftime(t_end, t_start));
    return 0;
}

void rand_abc(){
    int b;
    srand((unsigned int)time(NULL));
    for(int i=0; i<26; i++){
        b = rand() % 26;
        b += 'a';
        a[i] = b;
        printf("%c", b);
    }
    printf("\n");
}

void getchar_abc(){
    char c;
    int i = 0;
    for(int i=0; i<26; i++){
        c=getchar();
        if(c!='\0' && c!='\n'){
            b[i] = c;
        }
    }
}

int compare(){
    int i;
    int j = 0;
    double f;
    for(i=0;i<26;i++){
        if(a[i] == b[i]){
            ++j;
        }
    }
    f = (j / 26.0) * 100;
    printf("正确率为: %lf%%\n", f);
}