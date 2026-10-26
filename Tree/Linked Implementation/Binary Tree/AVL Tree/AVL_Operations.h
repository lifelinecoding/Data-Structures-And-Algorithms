#ifndef AVL_OPERATIONS_H
#define AVL_OPERATIONS_H
#include<stdio.h>
#include<stdlib.h>
#include"../definition.h"
#include"../Binary Search Tree/BST_Operations.h"

// Helper function to initialize a node.
AVL_Tree *initialize(AVL_Tree *node, int key){
    if(node == NULL) return NULL;
    node->key = key;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

//Helper function to get maximum.
int maximum(int x, int y){
    return (x > y)? x: y;
}
//Helper function to get the height of a subtree.
int height(AVL_Tree *node){
    if(node == NULL) return 0;
    return node->height + 1;
}

//Helper function to get Balance Factor of a node.
int balanceFactor(AVL_Tree *node){
    return height(node->left) - height(node->right);
}
//Function to rotate right
AVL_Tree * RotateRight(AVL_Tree *node){
    AVL_Tree * x = node->left;
    AVL_Tree * y = x->right;

    // Right rotation.
    x->right = node;
    node->left = y;

    // Updated the height.
    node->height = maximum(height(node->left), height(node->right));
    x->height = maximum(height(x->left), height(x->right));

    return x;
}
//Function to rotate left
AVL_Tree * RotateLeft(AVL_Tree *node){
    AVL_Tree * x = node->right;
    AVL_Tree * y = x->left;

    // Left rotation.
    x->left = node;
    node->right = y;

    // Updated the height.
    node->height = maximum(height(node->left), height(node->right));
    x->height = maximum(height(x->left), height(x->right));

    return x;
}
//Function to insert a new node in AVL tree
AVL_Tree *InsertAVL(AVL_Tree *root, int key){
    if(root == NULL){
        AVL_Tree *newNode = (AVL_Tree*)malloc(sizeof(AVL_Tree));
        if(newNode == NULL){
            printf("Memory allocation for new node is failed.\n");
            return root;
        }
        return initialize(newNode, key);
    }
    else if(key < root->key){
        root->left = InsertAVL(root->left, key);
    }
    else if( key > root->key){
        root->right = InsertAVL(root->right, key);
    }

    // Update the height after insertion.
    root->height = maximum(height(root->left), height(root->right));

    int balance = balanceFactor(root);
    
    // Rotation logic
    if(balance > 1 && key < root->left->key) return RotateRight(root);
    else if(balance < -1 && key > root->right->key) return RotateLeft(root);
    else if(balance > 1 && key > root->left->key){
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    else if(balance < -1 && key < root->right->key){
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    return root;
}
//TODO: Function to delete a new node in AVL tree


#endif      // Closing for AVL_OPERATIONS_H