#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *rFP = fopen(argv[1], "r");
    FILE *wFP = fopen(argv[2], "w");

    if(NULL == rFP){
        perror("open file error");
    }
    if(NULL == wFP){
        perror("open file error");
    }

    if(3 != argc){
        printf("use ./mycp src.txt dst.txt");
        return 0;
    }
    char buf[4*1024];
    char len;
    while(1){
        len = fread(buf, 1, sizeof(buf), rFP);
        if(0 == len){
            break;
        }
        fwrite(buf, 1, len, wFP);
    }
    fclose(rFP);
    fclose(wFP);
    return 0;
}

