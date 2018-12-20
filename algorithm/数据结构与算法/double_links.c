#include <stdio.h>
#include <stdlib.h>

typedef struct line{
    struct line * prior; //指向直接前趋
    int data;
    struct line * next; //指向直接后继
}line;

line * initLine(line * head);
line * insertLine(line * head, int data, int add);
line * delLine(line * head, int data);
int selectElem(line * head, int elem);
line *amendElem(line * p, int add, int newElem);
void display(line * head);

int main(){
    //创建一个头指针
    line * head=NULL;
    //调用链表创建函数
    head=initLine(head);
    //输出创建好的链表
    display(head);
    //显示双向链表的优点
//    printf("链表中第4个节点的直接前驱是: %d", head->next->next->next->prior->data);
//    printf("\n");
    head=insertLine(head, 7, 3);
    display(head);
    head=delLine(head, 2);
    display(head);

    printf("元素 3 的位置是：%d\n",selectElem(head,3));
    //表中第 3 个节点中的数据改为存储 6
    head = amendElem(head,3,6);
    display(head);
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

line * insertLine(line * head, int data, int add){
    //新建数据域为data的结点
    line * temp=(line *)malloc(sizeof(line));
    temp->data=data;
    temp->prior=NULL;
    temp->next=NULL;
    //插入到链表头, 要特殊考虑
    if(add==1){
        temp->next=head;
        head->prior=temp;
        head=temp;
    }else{
        line * body=head;
        //找到要插入位置的前一个结点
        for(int i=1; i<add-1; i++){
            body=body->next;
        }
        //判断条件为真, 说明插入位置为链表尾
        if(body->next==NULL){
            body->next=temp;
            temp->prior=body;
        }else{
            //将body的后继结点的前序结点赋予temp;
            body->next->prior=temp;
            //将body的后继结点赋予temp结点, 链接后面的元素
            temp->next=body->next;
            //链接前面body的元素
            //将body的后继结点赋予temp
            body->next=temp;
            temp->prior=body;
        }
    }
    return head;
}

//删除结点函数, data为要删除结点的数据域的值
line * delLine(line * head, int data){
    line * temp=head;
    //遍历链表
    while(temp){
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if(temp->data==data){
            //将所要删除元素的前继的后继结点赋予所要删除元素的后继结点
            temp->prior->next=temp->next;
            //将所要删除的后继结点的前继结点赋予所要删除元素的前继结点
            temp->next->prior=temp->prior;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    printf("链表中无该数据元素");
    return head;
}

//head为原双链表，elem表示被查找元素
int selectElem(line * head, int elem){
    //新建一个指针t, 初始化为头指针head
    line * t=head;
    int i=1;
    while(t){
        if(t->data==elem){
            return i;
        }
        i++;
        t=t->next;
    }
    //查找失败
    return -1;
}

//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
line * amendElem(line *p, int add, int newElem){
    line * temp=p;
    //遍历到被删除结点
    for(int i=1; i<add; i++){
        temp=temp->next;
    }
    temp->data=newElem;
    return p;
}


