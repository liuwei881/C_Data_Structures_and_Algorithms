#include <stdio.h>
#include "Binary_tree_h.h"

typedef struct TreeNode * PrtToNode;
typedef struct PrtToNode Tree;

struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;
};

SearchTree MakeEmpty(SearchTree T){
    if(T!=NULL){
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T){
    if(T==NULL){
        return NULL;
    }
    if(X< T->Element){
        return Find(X, T->Left);
    }else if(X> T->Element){
        return Find(X, T->Right);
    }else{
        return T;
    }
}

Position FindMin(SearchTree T){
    if(T==NULL){
        return NULL;
    }else if(T->Left==NULL){
        return T;
    }else{
        return FindMin(T->Left);
    }
}

Position FindMax(SearchTree T){
    if(T!=NULL){
        while(T->Right!=NULL){
            T=T->Right;
        }
    }
    return T;
}