#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PrtToNode List;
typedef PrtToNode Position;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
Position FindPrevious( ElementType X, List L );
void Insert( ElementType X, List L, Position P);
void DeleteList( List L);
Position Header( List L);
Position First( List L);
Position Advance( Position P );
ElementType Retrieve( Position P );

#endif

struct Node
{
    ElementType Element;
    Position    Next;
};

int IsEmpty( List L )
{
    return L->Next == NULL;
}

int IsLast( Position P, List L )
{
    return P->Next == NULL;
}

Position Find( ElementType X, List L )
{
    Position P;

    P = L->Next;
    while ( P != NULL && P->Element != X)
    {
        P = P->Next;
    }
    return P;
}

Position FindPrevious( ElementType X, List L)
{
    Position P;

    P = L;
    while ( P->Next != NULL && P->Next->Element != X )
    {
        P = P->Next;
    }
    return P;
}

void Delete( ElementType X, List L )
{
    Position P, TmpCell;

    P = FindPrevious( X, L );

    if ( !IsLast( P, L ) )
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free( TmpCell);
    }
}

void Insert( ElementType X, List L, Position P )
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if ( TmpCell == NULL )
    {
        FatalError( "Out of space!!!" );
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

