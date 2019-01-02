#include <stdio.h>

void PrintTree(SearchTree T){
    if(T != NULL){
        PrintTree(T->Left);
        PrintElement(T->Element);
        PrintTree(T->Right);
    }
}

int Height(Tree T){
    if(T == NULL){
        return -1;
    }else{
        return 1 + Max(Height(T->Left), Height(T->Right));
    }
}
