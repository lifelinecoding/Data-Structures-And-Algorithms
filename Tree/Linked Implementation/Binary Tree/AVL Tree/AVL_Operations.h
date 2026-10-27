#ifndef AVL_OPERATIONS_H
#define AVL_OPERATIONS_H
#include<stdio.h>
#include<stdlib.h>
#include"../definition.h"

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

// Function to find maximum in a binary search tree.
AVL_Tree * MaxInAVL(AVL_Tree *root){
    while(root != NULL && root->right != NULL){
        root = root->right;
    }
    return root;
}

// Function to find In-Order Successor of a node in binary search tree.
AVL_Tree *InOrderPredcessorAVL(AVL_Tree *root, int key){
    AVL_Tree *predcessor = NULL;
    if(root != NULL && root->left != NULL) return MaxInAVL(root->left);
    else if(root != NULL && root->left == NULL){
        while(root->key != key){
            if(key > root->key){
                predcessor = root;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
    return predcessor;
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
//Function to delete a new node in AVL tree
AVL_Tree *DeleteAVL(AVL_Tree *root, int key){
    AVL_Tree *temp = NULL;
    AVL_Tree *predcessor = NULL;

    if(root == NULL) return root;

    if(root->key == key){
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        else if(root->right != NULL && root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else{
            predcessor = InOrderPredcessorAVL(root, key);
            root->key = predcessor->key;
            root->left = DeleteAVL(root->left, predcessor->key);
        }
    }
    else if(key < root->key){
        root->left = DeleteAVL(root->left, key);
    }
    else{
        root->right = DeleteAVL(root->right, key);
    }

    // Update the height
    root->height = maximum(height(root->left), height(root->right));

    // Balance Factor.
    int balance = balanceFactor(root);

    // Rotation logic..
    if(balance > 1 && balanceFactor(root->left) >= 0) return RotateRight(root);
    else if(balance < -1 && balanceFactor(root->right) <= 0) return RotateLeft(root);
    else if(balance > 1 && balanceFactor(root->left) < 0){
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    else if(balance < -1 && balanceFactor(root->right) > 0){
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }
    
    return root;
}


#endif      // Closing for AVL_OPERATIONS_H