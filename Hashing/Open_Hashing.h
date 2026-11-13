#ifndef OPEN_HASHING_H
#define OPEN_HASHING_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"definition.h"

#ifndef SEPARATE_CHAINING
#define SEPARATE_CHAINING

// Helper functions for linked list operations.

// Function to insert a new node at the starting of the linked list.
Node* InsertAtStart(Node* head, int key){
    Node* current = head;
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->key = key;
   
    if(current == NULL){
        newNode->next = NULL;
        return newNode;
    }
    newNode->next = current;
    return newNode;
}

int Search(Node *head, int key){
    Node *current = head;
    while (current != NULL){
        if(current->key == key) return 1;
        current = current->next;
    }
    return 0;
}


// Function to delete a key in a linked list.
Node *DeleteOnKey(Node *head, int key){
    Node *current = head;
    Node *Next = head->next;
    // Check if their is any node in linked list or not.
    if(current == NULL){
        printf("No node exist in the list\n");
        return head;
    }

    // Checking if user want to delete the head.
    if (current->key == key)    {
        free(current);
        return Next;
    }

    // Traversing the list until the data is found
    while (Next != NULL){
        if (Next->key == key){
            current->next = Next->next;
            free(Next);
            return head;
        }
        current = current->next;
        Next = Next->next;
    }
    return head;
}

// Function to initialize hash table.
Open_Hash_Table *createHashTableOpen(Open_Hash_Table *table, int size){
    if(size <= 0) return NULL;
    table = (Open_Hash_Table*)malloc(sizeof(Open_Hash_Table));
    if(table == NULL){
        printf("Memory allocation failed for the hash table.\n");
        return NULL;
    }
    table->size = size;
    table->arr = (Node**)malloc(sizeof(Node*) * table->size);
    if(table->arr == NULL) return NULL;
    for(int i = 0; i < table->size; i++) table->arr[i] = NULL;
    return table;
}

// Function to free hash table
void freeHashTableOpen(Open_Hash_Table *table){
    if(table == NULL) return;
    if(table->arr != NULL) free(table->arr);
    free(table);
}

// Hash function (Division Method).
int hashOpen(int key, int table_size){
    return key % table_size;
}

// Function to insert a new key in hash table.
void insertKeyOpen(Open_Hash_Table *table, int key){
    if(table == NULL) return;
    int hashCode = hashOpen(key, table->size);
    if(hashCode < 0){
        hashCode = hashCode * -1;
    }
    table->arr[hashCode] = InsertAtStart(table->arr[hashCode], key);
}

// Function to delete a key in hash table.
void removeKeyOpen(Open_Hash_Table *table, int key){
    if(table == NULL) return;
    int hashCode = hashOpen(key, table->size);
    if(hashCode < 0){
        hashCode = hashCode * -1;
    }
    table->arr[hashCode] = DeleteOnKey(table->arr[hashCode], key);
}

// Function to search a key..
bool isKeyExistOpen(Open_Hash_Table *table, int key){
    if(table == NULL) return false;
    int hashCode = hashOpen(key, table->size);
    if(hashCode < 0){
        hashCode = hashCode * -1;
    }
    return Search(table->arr[hashCode], key);
}

// Function to display all elements in a hash table.
void DisplayHashTableOpen(Open_Hash_Table *table){
    if(table == NULL) return;
    for(int i = 0; i < table->size; i++){
        printf("%d | -> ", i);
        Node *temp = table->arr[i];
        while(temp != NULL){
            printf("%d ->", temp->key);
            temp = temp->next;
        }
        printf("NULL.\n");
    }
}
#endif          // Closing for SEPARATE_CHAINING
#endif          // Closing for OPEN_HASHING_H