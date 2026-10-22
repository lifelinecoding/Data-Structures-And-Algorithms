#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include"../definition.h"
#include<stdio.h>

// Pre-Order traversal of a binary tree
void PreOrder(Tree *root){
    if(root != NULL){
        printf("%d ", root->key);     // Root Node
        PreOrder(root->left);        // Left Subtree
        PreOrder(root->right);      // Right Subtree
    }
}

// In-Order traversal of a binary tree
void InOrder(Tree *root){
    if(root != NULL){
        InOrder(root->left);         // Left Subtree
        printf("%d ", root->key);   // Root Node
        InOrder(root->right);      // Right Subtree
    }
}

// Post-Order traversal of a binary tree
void PostOrder(Tree *root){
    if(root != NULL){
        PostOrder(root->left);        // Left Subtree
        PostOrder(root->right);      // Right Subtree
        printf("%d ", root->key);   // Root Node
    }
}

#endif