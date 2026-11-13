#ifndef CLOSED_HASHING_H
#define CLOSED_HASHING_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"definition.h"

// Funtion to initialize the hash table.
Closed_Hash_Table * createHashTableClosed(Closed_Hash_Table *table, int size){
    if(size <= 0) return NULL;
    table = (Closed_Hash_Table*)malloc(sizeof(Closed_Hash_Table));
    if(table == NULL){
        printf("Memory allocation for table is failed.\n");
        return NULL;
    }
    table->size = size;
    table->arr = (slot*)malloc(sizeof(slot) * table->size);
    if(table->arr == NULL){
        printf("Memory Allocation failed for hash table.\n");
        free(table);
        return NULL;
    }

    // Setting status to empty for each slot.
    for(int i = 0; i < table->size; i++){
        table->arr[i].status = EMPTY;
    }

    return table;
}

// Function to display hash table..
void DisplayHashTableClosed(Closed_Hash_Table * table){
    if(table == NULL) return;
    for(int i = 0; i < table->size; i++){
        printf("%d | %d | %d\n", i, table->arr[i].key, table->arr[i].status);
    }
}

// Function to free a hash table
void freeHashTableClosed(Closed_Hash_Table *table){
    if(table == NULL) return;
    if(table->arr != NULL) free(table->arr);
    free(table);
}

#ifndef LINEAR_PROBING
#define LINEAR_PROBING

// Original Hash Function
int hashLinear(int key, int table_size){
    return key % table_size;
}

// Function to insert a new key in hash table
void insertKeyLinear(Closed_Hash_Table *table, int key){
    if(table == NULL) return;
    int hashCodePermanant = -1;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        // Applying probing to resolve collision.
        int hashCode = (hashLinear(key, table->size) + probeIndex) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].status != OCCUPIED){
            hashCodePermanant = hashCode;
            break;
        }
    }

    // Store the new key in available slot.
    if(hashCodePermanant >= 0){
        table->arr[hashCodePermanant].key = key;
        table->arr[hashCodePermanant].status = OCCUPIED;
    }
}

// Function to delete a key in hash table.
void removeKeyLinear(Closed_Hash_Table *table, int key){
    if(table == NULL) return;
    int hashCodePermanant;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        int hashCode = (hashLinear(key, table->size) + probeIndex) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].key == key || table->arr[hashCode].status == EMPTY){
            hashCodePermanant = hashCode;
            break;
        }       
    }

    // Marking the slot as deleted just to prevent tombstone problem.
    if(table->arr[hashCodePermanant].status == EMPTY) return;
    if(table->arr[hashCodePermanant].key == key) table->arr[hashCodePermanant].status = DELETED;
}

// Funtion to search a key in hash table..
bool isKeyExistLinear(Closed_Hash_Table *table, int key){
    if(table == NULL) return false;
    int hashCodePermanant;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        int hashCode = (hashLinear(key, table->size) + probeIndex) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].key == key || table->arr[hashCode].status == EMPTY){
            hashCodePermanant = hashCode;
            break;
        }     
    }
    if(table->arr[hashCodePermanant].status == EMPTY) return false;
    if(table->arr[hashCodePermanant].key == key && table->arr[hashCodePermanant].status != DELETED) return true;
    else return false;
}

#endif  // Closing for LINEAR_PROBING

#ifndef QUADRATIC_PROBING
#define QUADRATIC_PROBING

// Original Hash Function..
int hashQuadratic(int key, int table_size){
    return key % table_size;
}

// Function to insert a new key
void insertKeyQuadratic(Closed_Hash_Table *table, int key){
    if(table == NULL) return;
    int hashCodePermanant = -1;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        // Applying probing to resolve collision.
        int hashCode = (hashQuadratic(key, table->size) + probeIndex*probeIndex) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].status != OCCUPIED){
            hashCodePermanant = hashCode;
            break;
        }
    }

    // Store the new key in available slot.
    if(hashCodePermanant >= 0){
        table->arr[hashCodePermanant].key = key;
        table->arr[hashCodePermanant].status = OCCUPIED;
    }
}

// Function to delete a key from hash table.
void removeKeyQuadratic(Closed_Hash_Table *table, int key){
    if(table == NULL) return;
    int hashCodePermanant;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        int hashCode = (hashQuadratic(key, table->size) + probeIndex*probeIndex) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].key == key || table->arr[hashCode].status == EMPTY){
            hashCodePermanant = hashCode;
            break;
        }  
    }
    // Marking the slot as deleted just to prevent tombstone problem.
    if(table->arr[hashCodePermanant].status == EMPTY) return;
    if(table->arr[hashCodePermanant].key == key) table->arr[hashCodePermanant].status = DELETED;
}

// Function to search a key in hash table..
bool isKeyExistQuadratic(Closed_Hash_Table *table, int key){
    if(table == NULL) return false;
    int hashCodePermanant;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        int hashCode = (hashQuadratic(key, table->size) + probeIndex*probeIndex) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].key == key || table->arr[hashCode].status == EMPTY){
            hashCodePermanant = hashCode;
            break;
        }    
    }
    if(table->arr[hashCodePermanant].status == EMPTY) return false;
    if(table->arr[hashCodePermanant].key == key && table->arr[hashCodePermanant].status != DELETED) return true;
    else return false;
}

#endif // Closing for QUADRATIC_PROBING

#ifndef DOUBLE_HASHING
#define DOUBLE_HASHING

// Original hash function 1.
int hashDouble1(int key, int table_size){
    return key % table_size;
}

// Hash function for step count in probing
int hashDouble2(int key, int table_size){
    return 7 - (key % table_size);
}

// Funtion to insert a new key in a hash table..
void insertKeyDouble(Closed_Hash_Table *table, int key){
    if(table == NULL) return;
    int hashCodePermanant = -1;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        // Applying probing to resolve collision.
        int hashCode = (hashDouble1(key, table->size) + probeIndex * hashDouble2(key, table->size)) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].status != OCCUPIED){
            hashCodePermanant = hashCode;
            break;
        }
    }

    // Store the new key in available slot.
    if(hashCodePermanant >= 0){
        table->arr[hashCodePermanant].key = key;
        table->arr[hashCodePermanant].status = OCCUPIED;
    }
}

// Function to remove a key from hash table..
void removeKeyDouble(Closed_Hash_Table *table, int key){
    if(table == NULL) return;
    int hashCodePermanant;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        int hashCode = (hashDouble1(key, table->size) + probeIndex * hashDouble2(key, table->size)) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].key == key || table->arr[hashCode].status == EMPTY){
            hashCodePermanant = hashCode;
            break;
        }
    }
    // Marking the slot as deleted just to prevent tombstone problem.
    if(table->arr[hashCodePermanant].status == EMPTY) return;
    if(table->arr[hashCodePermanant].key == key) table->arr[hashCodePermanant].status = DELETED;
}

// Function to search a key in hash table..
bool isKeyExistDouble(Closed_Hash_Table *table, int key){
    if(table == NULL) return false;
    int hashCodePermanant;
    for(int probeIndex = 0; probeIndex < table->size; probeIndex++){
        int hashCode = (hashDouble1(key, table->size) + probeIndex * hashDouble2(key, table->size)) % table->size;
        if(hashCode < 0) hashCode *= -1;
        if(table->arr[hashCode].key == key || table->arr[hashCode].status == EMPTY){
            hashCodePermanant = hashCode;
            break;
        }
    }
    if(table->arr[hashCodePermanant].status == EMPTY) return false;
    if(table->arr[hashCodePermanant].key == key && table->arr[hashCodePermanant].status != DELETED) return true;
    else return false;
}

#endif  // Closing for DOUBLE_HASHING

#endif  // Closing for CLOSED_HASHING_H