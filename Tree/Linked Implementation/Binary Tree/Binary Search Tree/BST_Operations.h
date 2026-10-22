#ifndef BST_OPERATIONS_H
#define BST_OPERATIONS_H
#include"../definition.h"
#include<stdio.h>
#include<stdlib.h>

// Function to search a node in Binary search tree.
Tree *SearchBST(Tree *root, int key){

    // Edge case if key is not available.
    if(root == NULL) return root;

    // Termination condition if key is found.
    if(root->key == key){
        return root;
    }
    else if(key < root->key){
        SearchBST(root->left, key);
    }else if(key > root->key){
        SearchBST(root->right, key);
    }
}

// Function to insert a new node in binary search tree
Tree *InsertBST(Tree *root, int key){
    if(root == NULL){
        Tree *node = (Tree*)malloc(sizeof(Tree));
        if(node == NULL){
            printf("Memory allocation failed for new node!\n");
            return root;
        }   
        node->key = key;
        node->left = node->right = NULL;
        return node;
    }
    else if(key < root->key){
        root->left = InsertBST(root->left, key);
    }
    else{
        root->right = InsertBST(root->right, key);
    }

    return root;
}

#endif      // closing for "BST_OPERATIONS_H"