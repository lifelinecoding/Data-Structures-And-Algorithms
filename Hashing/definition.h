#ifndef DEFINTION_H
#define DEFINTION_H

#ifndef OPEN_HASHING
#define OPEN_HASHING

typedef struct Node{
    int key;
    struct Node *next;
} Node;

typedef struct Open_Hash_Table{
    int size;
    Node **arr;
} Open_Hash_Table;

#endif      // CLosing for OPEN_HASHING

#endif      // Closing for DEFINTION_H