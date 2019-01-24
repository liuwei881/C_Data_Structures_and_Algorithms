#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//以这种结构体方式写入文件并读取

void write_file();
void read_file();
void write_file2();
void read_file2();

typedef struct Student{
    char *name;
    int id;
    int name_len;
} Stu;

int main(){
    //write_file();
    //read_file();

    write_file2();
    read_file2();
    return 0;
}

void write_file(){
    Stu s;
    s.id = 1;
    s.name_len = strlen("mike");
    s.name = (char *)malloc(s.name_len + 1);
    strcpy(s.name, "mike");


    FILE *fp = fopen("./13.txt", "w");
    if(NULL == fp){
        perror("open file error");
    }
    fwrite(&s, 1, sizeof(Stu), fp);
    fclose(fp);
}

void read_file(){
    FILE *fp = fopen("./13.txt", "r");
    if(NULL == fp){
        perror("open file error");
    }
    char buf[4*1024];
    Stu s;
    int len;
    while(1){
        len = fread(&s, 1, sizeof(Stu), fp);
        if(0 == len){
            break;
        }
        printf("%d,%s,%d\n", s.id, s.name, s.name_len);
    }
    fclose(fp);
}

void write_file2(){
    Stu s[3];
    char *buf[3] = {"liuwei", "mike", "zhangsan"};
    int i=0;
    for(i; i<3; i++){
        s[i].id = i;
        s[i].name_len = strlen(buf[i]);
        s[i].name = (char *)malloc(s[i].name_len + 1);
        strcpy(s[i].name, buf[i]);
    }

    FILE *fp = fopen("./13.txt", "w");
    if(NULL == fp){
        perror("open file error");
    }
    for(int i=0; i<3; i++){
        fwrite(&s[i], 1, sizeof(Stu), fp);
    }
    fclose(fp);
}

void read_file2(){
    FILE *fp = fopen("./13.txt", "r");
    if(NULL == fp){
        perror("open file error");
    }
    char buf[4*1024];
    Stu s[3];
    int len;
    for(int i=0; i<3; i++){
        len = fread(&s[i], 1, sizeof(Stu), fp);
        if(0 == len){
            break;
        }
        printf("%d, %s, %d\n", s[i].id, s[i].name, s[i].name_len);
    }
    fclose(fp);
}




