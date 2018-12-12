#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int  elem;
    struct Link *next;
}link;

link * initLink(){
    link * p = (link*)malloc(sizeof(link));
    link * temp = p;
    for (int i=1; i<5; i++) {
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

//p为原链表, elem表示新数据元素, add表示新元素要插入的位置
link * insertElem(link * p, int elem, int add){
    link * temp = p; //创建临时节点temp
    //首先找到要插入位置的上一个节点
    for (int i=1; i<add; i++){
        if (temp == NULL){
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    //创建插入节点c
    link * c = (link *)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入节点
    c->next = temp->next; //将要插入的c的next指针指向temp下个节点
    temp->next = c; //将c赋予temp的下个节点完成插入
    return p;
}

//p为原链表, add为要删除元素的值
link * delElem(link * p, int add){
    link * temp = p;
    //temp指向被删除节点的上一个节点
    for (int i=1; i<add; i++){
        temp = temp->next;
    }
    link * del = temp->next;//单独设置一个点指向被删除的元素,防止丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该节点, 防止内存泄漏
    return p;
}

//p为原链表, elem表示被查找元素
int selectElem(link * p, int elem){
    //新建一个指针t, 初始化为头指针p
    link * t = p;
    int i = 1;
    //由于头节点的存在, 因此while中的判断为t->next
    while (t->next){
        t = t->next;
        if (t->elem == elem){
            return i;
        }
        i++;
    }
    //没有找到返回-1
    return -1;
}

//更新函数,其中 add 表示更改结点在链表中的位置, newElem 为新的数据域的值
link * amendElem(link * p, int add, int newElem){
    link * temp = p;
    temp = temp->next; //遍历之前, temp指向首元结点
    //遍历到被更新的结点
    for (int i=1; i<add; i++){
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}


