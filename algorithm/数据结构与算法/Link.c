#include <stdio.h>

typedef struct Link {
    char elem; //数据域
    struct Link * next; //指针域，指向后继元素
} link; //link为节点名，每个节点都是一个 link 结构体

