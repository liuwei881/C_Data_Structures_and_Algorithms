#include <stdio.h>

typedef struct TreeNode * PrtToNode;
typedef struct PrtToNode Tree;

struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;
};
