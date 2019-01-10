#include <stdio.h>

int main(int argc, char *argv[]){
    int c;
    FILE *fp = fopen(argv[1], "r");
    if(NULL == fp){
        perror("fp");
    }
    while(1){
        c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}
