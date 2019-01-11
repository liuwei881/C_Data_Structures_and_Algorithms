#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    //打卡文件
    FILE *fp = fopen(argv[1], "w");
    if(NULL == fp){
        perror("file not found");
    }
    int i;
    char buff[1024];
    while(1){
        fgets(buff, 1024, stdin);
        if(0 == strncmp(buff, ":wq", 3)){
            break;
        }
        fputs(buff, fp);
    }
    //关闭文件
    fclose(fp);
    return 0;
}
