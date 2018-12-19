#include <stdio.h>

typedef struct TreeNode *PtrToNode;

struct TreeNode{
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};

static void ListDir(DirectoryOrFile D, int Depth){
    if(D is a legitimate entry){
        PrintName(D, Depth);
        if(D is a directory){
            for(each child, C, of D){
                ListDir(C, Depth+1);
            }
        }
    }
}

void ListDirectory(DirectoryOrFile D){
    ListDir(D, 0);
}

static void SizeDirectory(DirectoryOrFile D){
    int TotalSize;

    TotalSize = 0;
    if(D is a legitimate entry){
        TotalSize = FileSize(D);
        if(D is a directory){
            for(each child, C of D){
                TotalSize += SizeDirectory(C);
            }
        }
    }
    return TotalSize;
}