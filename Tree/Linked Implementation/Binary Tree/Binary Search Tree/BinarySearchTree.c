#include<stdio.h>
#include<windows.h>
#include"../definition.h"
#include"BST_Operations.h"
#include"../Traversal/traversal.h"


int main(){
    Tree *root = NULL;
    root = InsertBST(root, 50);
    root = InsertBST(root, 40);
    root = InsertBST(root, 55);
    root = InsertBST(root, 30);
    root = InsertBST(root, 45);
    root = InsertBST(root, 10);
    root = InsertBST(root, 52);
    root = InsertBST(root, 60);

    printf("In-Order Traversal: ");
    InOrder(root);
    printf("\n");

    root = DeleteBST(root, 10);
    root = DeleteBST(root, 52);
    root = DeleteBST(root, 55);

    printf("In-Order Traversal: ");
    InOrder(root);
    
return 0;
}