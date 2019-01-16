#include <stdio.h>
#include <string.h>

void write_file();
void read_file();
int calc_compute(int a, int b, char ch);

int main(){
    write_file();
    read_file();
    return 0;
}

int calc_compute(int a, int b, char ch){
    switch(ch){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
    return 0;
}

void write_file(){
    FILE *fp = fopen("./calc.txt", "w");
    if(NULL == fp){
        perror("file open error");
    }

    fputs("10+5=\n", fp);
    fputs("10-5=\n", fp);
    fputs("10*5=\n", fp);
    fputs("10/5=\n", fp);
    fputs("10+1=\n", fp);
    fputs("10-1=\n", fp);
    fputs("10*10=\n", fp);
    fputs("10/10=\n", fp);

    fclose(fp);
    fp = NULL;
}

void read_file(){
    FILE *fp = fopen("./calc.txt", "r");
    if(NULL == fp){
        perror("file open error");
    }

    char buff[1024];
    char tmp[1024] = {0};
    int a, b;
    char ch;
    while(1){
        fgets(buff, sizeof(buff), fp);
        if(feof(fp)){
            break;
        }
        if(strlen(buff) > 0){
            sscanf(buff, "%d%c%d=\n", &a, &ch, &b);
            //printf("%d%c%d=%d\n", a, ch, b, calc_compute(a, b, ch));
            sprintf(buff, "%d%c%d=%d\n", a, ch, b, calc_compute(a, b, ch));
            strcat(tmp, buff);
        }
    }
    fclose(fp);
    fp = NULL;
    fp = fopen("./calc.txt", "w");
    fputs(tmp, fp);
    fclose(fp);
}
