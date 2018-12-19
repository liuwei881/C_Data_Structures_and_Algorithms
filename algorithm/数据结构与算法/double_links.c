#include <stdio.h>
#include <stdlib.h>

typedef struct line{
    struct line * prior; //指向直接前趋
    int data;
    struct line * next; //指向直接后继
}line;

line * initLine(line * head);
void display(line * head);

int main(){
    //创建一个头指针
    line * head=NULL;
    //调用链表创建函数
    head=initLine(head);
    //输出创建好的链表
    display(head);
    //显示双向链表的优点
    printf("链表中第4个节点的直接前驱是: %d", head->next->next->next->prior->data);
    printf("\n");
    return 0;
}

line * initLine(line * head){
    head=(line *)malloc(sizeof(line)); //创建链表第一个节点(首元结点)
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    line * list=head;
    for(int i=2; i<=5; i++){
        //创建并初始化一个新结点
        line * body=(line *)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;

        list->next=body; //直接前趋结点的next指针指向新节点
        body->prior=list; //新结点指向直接前趋结点
        list=list->next;
    }
    return head;
}

void display(line * head){
    line * temp=head;
    while(temp) {
        //如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        } else {
            printf("%d <->", temp->data);
        }
        temp = temp->next;
    }
}


