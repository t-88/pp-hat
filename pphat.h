#ifndef PP_HAT_H
#define PP_HAT_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define LOAD_FACTOR 0.75
#define INIT_CAPACITY 6
#define FNV_OFFSET 0xcbf29ce484222325
#define FNV_PRIME 0x100000001b3
#define PPHAT_TALBE_GROWTH_RATE 2

typedef struct {
    size_t id;
    char* key;
    int value;
} Entry; 

typedef struct {
    size_t capaciy;
    size_t count;
    Entry* entries;
} PpHat;


PpHat* pphat_create_opt(size_t capacity,size_t count);
PpHat* pphat_create();  
void pphat_free(PpHat* table); 
void pphat_insert(PpHat** table,char* name,int value);
size_t pphat_get_hash(const char* id);
size_t pphat_fnv(const char* id);
void pphat_print(const PpHat* table);
PpHat* pphat_resize(PpHat* table);

void pphat_remove();  
void pphat_get();     
void pphat_contains();
void pphat_clear();   


//TODO: use string intering  
bool pphat_str_eq(char* str1,char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    return (len1 == len2) && (memcmp(str1,str2,len1) == 0);
}   


PpHat* pphat_create_opt(size_t capacity,size_t count) {
    PpHat* table  = (PpHat*) calloc(1,sizeof(PpHat));
    table->entries = (Entry*) calloc(capacity,sizeof(Entry));
    table->capaciy = capacity;
    table->count = count;
    return table;
}
PpHat* pphat_create() {
    return pphat_create_opt(INIT_CAPACITY,0);
}





void pphat_free(PpHat* table) { 
    table->capaciy = 0;
    table->count = 0;
    free(table->entries);
    free(table);
}


void pphat_insert(PpHat** table,char* key,int value) {    
    if((*table)->count + 1 >= (*table)->capaciy * LOAD_FACTOR) {
        (*table) = pphat_resize(*table);
    }

    size_t id = pphat_get_hash(key);
    size_t idx = id % (*table)->capaciy; 
    
    while (1) {
        if((*table)->entries[idx].key == NULL) {
            (*table)->entries[idx].value = value;
            (*table)->entries[idx].key = key;
            (*table)->count++;
            break;
        } else if(pphat_str_eq(key,(*table)->entries[idx].key)){
            (*table)->entries[idx].value = value;
            break;
        }
        idx = (idx + 1) % (*table)->capaciy;
    }
    

}

PpHat* pphat_resize(PpHat* table) {
    PpHat* tbl = pphat_create_opt(table->capaciy * PPHAT_TALBE_GROWTH_RATE,table->count);
    
    size_t idx = 0; 
    while (idx < table->capaciy) {
        if(table->entries[idx].key != NULL) {
            pphat_insert(&tbl,table->entries[idx].key,table->entries[idx].value);
        }
        idx++;
    }
    pphat_free(table);
    return tbl;
}


size_t pphat_get_hash(const char* id)  {
    return pphat_fnv(id);
}
size_t pphat_fnv(const char* id) {
    size_t hash = FNV_OFFSET;
    size_t curr = 0;
    while(id[curr] != 0) {
        hash = hash * FNV_PRIME;
        hash = hash ^ id[curr];
        curr++;
    }
    return hash;
}


void pphat_print(const PpHat* table) {
    printf("{\n");
    size_t idx = 0; 
    while(idx < table->capaciy) {
        if(table->entries[idx].key != NULL) {
            printf("  '%s' : %d\n",table->entries[idx].key,table->entries[idx].value);
        }
        idx++;
    }
    printf("}\n");
}


#endif // PP_HAT_H