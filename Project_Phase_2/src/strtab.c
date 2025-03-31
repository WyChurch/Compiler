#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "strtab.h"






//to fix "types" being undefined line 95
const char *types[] = {"int", "char", "void"};
//for "symTypeMod" also being undefined line 96
const char *symTypeMod[] = {"", "[]", "()"};  // SCALAR, ARRAY, FUNCTION






/* Provided is a hash function that you may call to get an integer back. */
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c == *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int ST_insert(char *id, char *scope, int data_type, int symbol_type){
    // TODO: Concatenate the scope and id and use that to create the hash key
    char key[256]; //scope + id
    snprintf(key, sizeof(key), "%s%s", scope, id);  
   
    // TODO: Use ST_lookup to check if the id is already in the symbol table. If yes, ST_lookup will return an index that is not -1. if index != -1, that means the variable is already in the hashtable. Hence, no need to insert that variable again. However, if index == -1, then use linear probing to find an empty spot and insert there. Then return that index.
     int index = ST_lookup(id, scope);
     if (index != -1) 
     {
     return index;   //don't need to insert variable
     }

     //if index == -1
     unsigned long h = hash((unsigned char *)key) % MAXIDS;
     unsigned long start = h;
 
     while (strTable[h].id != NULL) 
     {
         h = (h + 1) % MAXIDS;
         if (h == start) 
         {
             fprintf(stderr, "Symbol table is full\n");
             exit(1);
         }
     }
     //insert new entry insymbol table
    strTable[h].id = strdup(id);
    strTable[h].scope = strdup(scope);
    strTable[h].data_type = data_type;
    strTable[h].symbol_type = symbol_type;

    return h;
}

int ST_lookup(char *id, char *scope) {
    // TODO: Concatenate the scope and id and use that to create the hash key
    char key[256]; //scope + id
    snprintf(key, sizeof(key), "%s%s", scope, id);

    // TODO: Use the hash value to check if the index position has the "id". If not, keep looking for id until you find an empty spot. If you find "id", return that index. If you arrive at an empty spot, that means "id" is not there. Then return -1. 
    unsigned long h = hash((unsigned char *)key) % MAXIDS;
    unsigned long start = h;

    while (strTable[h].id != NULL) 
    {
        //return index
        if (strcmp(strTable[h].id, id) == 0 && strcmp(strTable[h].scope, scope) == 0) {
            return h;
        }

        //find an empty spot.
        h = (h + 1) % MAXIDS;

        if (h == start) {
            //nothing found
            break;
        }
    }

    return -1;
}

void output_entry(int i){
    printf("%d: %s ", i, types[strTable[i].data_type]);
    printf("%s:%s%s\n", strTable[i].scope, strTable[i].id, symTypeMod[strTable[i].symbol_type]);
}

