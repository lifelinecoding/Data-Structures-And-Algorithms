// Checking if a binary tree is binary search tree.

#include<stdio.h>
#include<windows.h>
#include<limits.h>
#include<stdbool.h>
#include<stdlib.h>
#include"../Tree/Linked Implementation/Binary Tree/definition.h"

// Range based check
bool IsBinarySearchTreeRange(Tree *root, int min, int max){
    if(root == NULL) return true;
    if(root->key < min || root->key > max) return false;
    return IsBinarySearchTreeRange(root->left, min, root->key) && IsBinarySearchTreeRange(root->right, root->key, max);
}

// Inorder Traversal
bool IsBinarySearchTreeInOrder(Tree *root, Tree **prev){
    if(root == NULL) return true;
    if(!IsBinarySearchTreeInOrder(root->left, prev)) return false;

    if(*prev != NULL && root->key <= (*prev)->key) return false;

    *prev = root;

    return IsBinarySearchTreeInOrder(root->right, prev);
}

// Function to create a node in tree
Tree * createNode(int key){
    Tree *newNode = (Tree*)malloc(sizeof(Tree));
    if(newNode == NULL) return NULL;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int main(){
    Tree *root = NULL;
    Tree *prev = NULL;

    root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(9);

    if(IsBinarySearchTreeRange(root, INT_MIN, INT_MAX)) printf("Tree is a valid BST.\n");
    else printf("Tree is not a valid BST.\n");

    if(IsBinarySearchTreeInOrder(root, &prev)) printf("Tree is a valid BST.\n");
    else printf("Tree is not a valid BST.\n");
return 0;
}