#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "strtab.h"

symEntry strTable[MAXIDS];

/*THIS WAS ALL COPIED AND PASTED FROM THE PHASE 2 OF THE PROJECT. 
A LOT WILL NEED TO BE CHAGED AND ERRORS WILL POP UP BECAUSE OF MISSING FUNCTIONS 
OR DIFFERENT ARGUMENTS WITHIN FUNCTIONS IN THE HEADER FILE*/

param *working_list_head = NULL;
param *working_list_end = NULL;
table_node *current_scope = NULL;

//to fix "types" being undefined line 95
const char *types[] = {"int", "char", "void"};
//for "symTypeMod" also being undefined line 96
const char *symTypeMod[] = {"", "[]", "()"};  // SCALAR, ARRAY, FUNCTION

void print_sym_tab(void) {
    printf("---- Symbol Table ----\n");
    for (int i = 0; i < MAXIDS; i++) {
        if (strTable[i].id != NULL) {
            printf("ID: %-10s | Scope: %-10s | Type: %d | SymType: %d\n",
                   strTable[i].id,
                   strTable[i].scope,
                   strTable[i].data_type,
                   strTable[i].symbol_type);
        }
    }
    printf("-----------------------\n");
}

/* Provided is a hash function that you may call to get an integer back. */
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int ST_insert(char *id, char *scope, int data_type, int symbol_type){
    char key[256]; //scope + id
    snprintf(key, sizeof(key), "%s%s", scope, id);  
   
    
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

//TODO: CHANGE ME TO MATCH HEADER
int ST_lookup(char *id, char *scope) {
    char key[256]; //scope + id
    snprintf(key, sizeof(key), "%s%s", scope, id);

    
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

void add_param(int data_type, int symbol_table){
    param *new_param = (param*)malloc(sizeof(param));
    new_param->data_type = data_type;
    new_param->symbol_type = symbol_table;
    new_param->next = NULL;

    if (working_list_head == NULL){
        working_list_head = new_param;
        working_list_end = new_param;
        return;
    }
    param* current = working_list_end;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_param;
    working_list_end = new_param;
}

void connect_params(int i, int num_params){
    current_scope->parent->strTable[i]->params = working_list_head;
    if (!current_scope || !current_scope->parent) {
        fprintf(stderr, "Error: current_scope or parent is NULL in connect_params.\n");
        return;
    }
}

void new_scope(){
    table_node* new_scope = (table_node*)malloc(sizeof(table_node));
    memset(new_scope->strTable, 0, sizeof(new_scope->strTable));
    new_scope->numChildren = 0;
    new_scope->parent = current_scope;
    new_scope->first_child = NULL;
    new_scope->last_child = NULL;
    new_scope->next = NULL;

    if (current_scope) {
        if (!current_scope->first_child) {
            current_scope->first_child = new_scope;
        } else {
            current_scope->last_child->next = new_scope;
        }
        current_scope->last_child = new_scope;
        current_scope->numChildren++;
    }

    current_scope = new_scope;
}

void up_scope(){
    current_scope = current_scope->parent;
}

void output_entry(int i){
    printf("%d: %s ", i, types[strTable[i].data_type]);
    printf("%s:%s%s\n", strTable[i].scope, strTable[i].id, symTypeMod[strTable[i].symbol_type]);
}

const char* get_symbol_id(int index) {
    if (index >= 0 && index < MAXIDS && strTable[index].id != NULL)
        return strTable[index].id;
    return "??";
}