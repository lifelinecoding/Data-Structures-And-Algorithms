#ifndef DEFINITION_H
#define DEFINITION_H

// Definition of a general binary tree.
typedef struct Tree{
    int key;
    struct Tree *left;
    struct Tree *right;
} Tree;

// Definition of a AVL tree.
typedef struct AVL_Tree{
    int key;
    struct AVL_Tree *left;
    struct AVL_Tree *right;
    int height;
} AVL_Tree;

#endif  // CLosing for "DEFINITION_H"