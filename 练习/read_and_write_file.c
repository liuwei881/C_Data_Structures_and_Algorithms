#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500

void write_file();
void read_file();

int main(){
    write_file();
    read_file();
    return 0;
}

void write_file(){
    FILE *fp = fopen("./read.txt", "w");
    srand((unsigned)(time(NULL)));
    int i=0;
    int r;
    char str[MAX];
    for(i; i<MAX; i++){
        r = rand() % MAX;
        sprintf(str, "%d\n", r);
        fputs(str, fp);
    }
    fclose(fp);
}

void read_file(){
    FILE *fp = fopen("./read.txt", "r");
    int i=0;
    int d;
    int a[MAX];
    char b[MAX];
    for(i; i<MAX; i++){
        fgets(b, MAX, fp);
        sscanf(b, "%d", &d);
        if(feof(fp)){
            break;
        }
        a[i] = d;
    }
    for(i=0; i<MAX; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    fclose(fp);
}
