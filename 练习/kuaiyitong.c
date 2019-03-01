#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

struct dict{
    char *key;
    char *content;
};

void get_dict(struct dict **tmp){
    *tmp = (struct dict *)malloc(MAX * sizeof(struct dict));
    if(*tmp == NULL){
        return;
    }

    (*tmp)[0].key = (char *)malloc(strlen("a") + 1);
    strcpy((*tmp)[0].key, "a");

    (*tmp)[0].content = (char *)malloc(strlen("art.字母a") + 1);
    strcpy((*tmp)[0].content, "art.字母a");

    (*tmp)[1].key = (char *)malloc(strlen("a.m.") + 1);
    strcpy((*tmp)[1].key, "a.m.");

    (*tmp)[1].content = (char *)malloc(strlen("art.下午") + 1);
    strcpy((*tmp)[1].content, "art.下午");

    (*tmp)[2].key = (char *)malloc(strlen("abandom") + 1);
    strcpy((*tmp)[2].key, "abandom");

    (*tmp)[2].content = (char *)malloc(strlen("art.抛弃, 放弃") + 1);
    strcpy((*tmp)[2].content, "art.抛弃, 放弃");
}

void print_dict(struct dict *tmp){
    int i = 0;
    for(i; i < MAX; ++i){
        printf("[%s] %s\n", tmp[i].key, tmp[i].content);
    }
}

void free_dict(struct dict *tmp){
    int i;
    for(i=0; i < MAX; i++){
        if(tmp[i].key != NULL){
            free(tmp[i].key);
            tmp[i].key = NULL;
        }
        if(tmp[i].content != NULL){
            free(tmp[i].content);
            tmp[i].content = NULL;
        }
        free(tmp);
        tmp = NULL;
    }
}

int search_dict(struct dict *tmp, char *key, char *content){
    int i = 0;
    for(i=0; i < MAX; i++){
        if(strcmp(tmp[i].key, key) == 0){
            strcpy(content, tmp[i].content);
            return 1;
        }
    }
    return 0;
}

int main(){
    struct dict *p = NULL;
    get_dict(&p);
    print_dict(p);

    //查询功能
    char key[1024];
    char content[1024];

    while(1){
        printf("请输入需要查询的单词: ");
        scanf("%s", key);
        if(strcmp(key, "break")){
            printf("没有此单词");
            break;
        }

        //如果有返回为真, 没有返回为假
        int flag = search_dict(p, key, content);
        if(flag == 0){
            printf("没有此单词: %s\n", key);
        }else{
            printf("[%s]的解释为: %s\n", key, content);
        }
    }

    free_dict(p);

    return 0;
}