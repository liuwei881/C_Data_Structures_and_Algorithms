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

    (*tmp)[0]->key = (char *)malloc(strlen("a") + 1);
    strcpy((*tmp)[0]->key, "a");

    (*tmp)[0]->content = (char *)malloc(strlen("art.字母a") + 1);
    strcpy((*tmp)->content, "art.字母a");



}

int main(){
    return 0;
}