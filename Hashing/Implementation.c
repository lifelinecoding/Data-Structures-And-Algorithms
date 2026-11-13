#include<stdio.h>
#include<windows.h>
#include"Open_Hashing.h"
#include"Closed_Hashing.h"
#include"definition.h"

int main(){
    // Open_Hash_Table *table;
    // table = createHashTableOpen(table, 10);
    // insertKeyOpen(table, 67);
    // insertKeyOpen(table, 43);
    // insertKeyOpen(table, -96);
    // insertKeyOpen(table, 21);
    // insertKeyOpen(table, 33);
    // insertKeyOpen(table, 77);
    // insertKeyOpen(table, -13);
   
    // removeKeyOpen(table, -96);
    // DisplayHashTableOpen(table);

    // printf("%d ", isKeyExistOpen(table, 77));
    // freeHashTableOpen(table);

    Closed_Hash_Table *table = NULL;
    table = createHashTableClosed(table, 10);
     
    // Linear Probing..
    // insertKeyLinear(table, 12);
    // insertKeyLinear(table, 22);
    // insertKeyLinear(table, 42);
    // insertKeyLinear(table, 38);

    // removeKeyLinear(table, 22);
    // removeKeyLinear(table, 42);
    //  DisplayHashTableClosed(table);
    // printf("%d ", isKeyExistLinear(table, 12));

    // Quadratic Probing..
    insertKeyQuadratic(table, 12);
    insertKeyQuadratic(table, 22);
    insertKeyQuadratic(table, 32);
    insertKeyQuadratic(table, 52);

    removeKeyQuadratic(table, 52);

    DisplayHashTableClosed(table);
    freeHashTableClosed(table);

return 0;
}