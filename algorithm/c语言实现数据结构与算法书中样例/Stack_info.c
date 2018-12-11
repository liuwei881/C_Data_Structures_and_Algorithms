#include <stdio.h>
#include <stdlib.h>

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord{
    int Capacity;
    int TopOfStack;
    ElementType * Array;
};

Stack CreateStack(int MaxElements){
    Stack S;

    if(MaxElements < MinStackSize){
        Error("Stack size is too small");
    }

    S = malloc(sizeof(struct StackRecord));
    if(S == NULL){
        FatalError("Out of space!!!");
    }

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if(S->Array == NULL){
        FatalError("Out of space!!!");
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S){
    if(S != NULL){
        free(S->Array);
        free(S);
    }
}

int IsEmpty(Stack S){
    return S->TopOfStack == EmptyTOS;
}