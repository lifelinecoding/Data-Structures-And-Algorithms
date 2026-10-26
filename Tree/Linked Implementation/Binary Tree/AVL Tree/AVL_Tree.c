#include<stdio.h>
#include<windows.h>
#include"AVL_Operations.h"
#include"../Binary Search Tree/BST_Operations.h"
#include"../definition.h"
#include"../Traversal/traversal.h"


int main(){
    AVL_Tree *root = NULL;
    root = InsertAVL(root, 10);
    root = InsertAVL(root, 15);
    root = InsertAVL(root, 5);
    root = InsertAVL(root, 25);
    root = InsertAVL(root, 18);
    root = InsertAVL(root, 2);

    PreOrderAVL(root);

return 0;
}