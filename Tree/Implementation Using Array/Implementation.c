#include<stdio.h>
#include<windows.h>
#define Capacity 10

// Tree Definition
struct Tree{
    int keys[Capacity];
    int size;
};

// Type definition
typedef struct Tree Tree;

// Function to initialize empty tree.
void initialize(Tree *root){
    root->size = -1;
}

// Function to insert a new key
void insert(Tree *root, int key){
    if(root->size < Capacity){
        root->keys[++(root->size)] = key;
    }
}

// Preorder traversal of tree elements
void Traverse(Tree *root, int index){
    if(index <= root->size){
        printf("%d ", root->keys[index]);
        Traverse(root, 2*index + 1);
        Traverse(root, 2*index + 2);
    }
}

// Sequential traversal of tree elements.
void print(int arr[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    Tree tree;
    initialize(&tree);
    insert(&tree, 8);
    insert(&tree, 7);
    insert(&tree, 6);
    insert(&tree, 4);
    insert(&tree, 2);
    insert(&tree, 12);
    insert(&tree, 36);
    insert(&tree, 25);
    insert(&tree, 9);
    insert(&tree, 19);

    print(tree.keys, 10);
    printf("\n");
    Traverse(&tree, 0);
return 0;
}