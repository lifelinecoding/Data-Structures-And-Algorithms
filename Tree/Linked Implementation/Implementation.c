#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

// Node Defintion
struct Node{
    int key;
    struct Node *first_child;
    struct Node *second_child;
    struct Node *third_child;
};

// Type definition of node
typedef struct Node Node;

// Tree definition
struct Tree{
    Node *root;
};

// Type definition of tree
typedef struct Tree Tree;

// Function to create a new Node
Node* CreateNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = data;
    newNode->first_child = NULL;
    newNode->second_child = NULL;
    newNode->third_child = NULL;
    return newNode;
}

// Print the tree
void printTree(Node *root){
    Node *current = root;
    if(current != NULL){
        printf("%d ", current->key);
        printTree(current->first_child);
        printTree(current->second_child);
        printTree(current->third_child);
    }
}

int main(){
    Tree t1;
    t1.root = NULL;
    
    //  Level 1
    t1.root = CreateNode(1);

    // Level 2
    t1.root->first_child = CreateNode(2);
    t1.root->second_child = CreateNode(3);
    t1.root->third_child = CreateNode(4);
    
    // Level 3
    t1.root->first_child->first_child = CreateNode(5);
    t1.root->first_child->second_child = CreateNode(6);

    t1.root->third_child->first_child = CreateNode(7);
    t1.root->third_child->second_child = CreateNode(8);

    // Level 4
    t1.root->first_child->first_child->first_child = CreateNode(9);

    // print the nodes.
    printTree(t1.root);

    // Free all nodes
    free(t1.root);
    free(t1.root->first_child);
    free(t1.root->second_child);
    free(t1.root->third_child);
    free(t1.root->first_child->first_child);
    free(t1.root->first_child->second_child);
    free(t1.root->first_child->first_child->first_child);
    free(t1.root->third_child->first_child);
    free(t1.root->third_child->second_child);

return 0;
}