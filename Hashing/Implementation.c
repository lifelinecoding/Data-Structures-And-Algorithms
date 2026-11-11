#include<stdio.h>
#include<windows.h>
#include"Open_Hashing.h"
#include"definition.h"

int main(){
    Open_Hash_Table *table;
    table = createTable(table, 10);
    insertKey(table, 67);
    insertKey(table, 43);
    insertKey(table, -96);
    insertKey(table, 21);
    insertKey(table, 33);
    insertKey(table, 77);
    insertKey(table, -13);
   
    removeKey(table, -96);
    // DisplayHashTable(table);

    printf("%d ", isKeyExist(table, 77));
return 0;
}