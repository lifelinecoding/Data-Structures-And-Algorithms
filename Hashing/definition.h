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

#ifndef CLOSED_HASHING
#define CLOSED_HASHING

// Enum to show slot status.
typedef enum {
    EMPTY,
    OCCUPIED,
    DELETED
} Status;

typedef struct slot{
    int key;
    Status status;
} slot;

typedef struct Closed_Hash_Table{
    int size;
    slot *arr;
} Closed_Hash_Table;

#endif      // Closing for CLOSED_HASHING

#endif      // Closing for DEFINTION_H