#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pphat.h"

int main(void) {
    srand(time(NULL));


    PpHat* table = pphat_create();

    pphat_insert(&table,"abc",rand() % 255);
    pphat_insert(&table,"1",rand() % 255);
    pphat_insert(&table,"2",rand() % 255);
    pphat_insert(&table,"3",rand() % 255);
    pphat_insert(&table,"km",rand() % 255);
    pphat_insert(&table,"5",rand() % 255);
    pphat_insert(&table,"6",rand() % 255);

    
    pphat_insert(&table,"1",69);
    pphat_insert(&table,"km",420);
    printf("Table:\n");
    pphat_print(table);

    printf("Table get value: %d\n",pphat_get(table,"abc"));
    printf("Table contains value `abcd`: %s\n",pphat_contains(table,"abcd") ? "True" : "False");

    pphat_remove(table,"km");
    printf("Table remove key 'km':\n");
    pphat_print(table);


    pphat_free(table);


    table = pphat_create();
    // collision in key `1` and `7` and `=`
    printf("Table collision check:\n");
    printf("hash: `1`: %lu,\n      `7`: %lu,\n      `=`: %lu,\n     \n",
                           pphat_get_hash("1") % table->capaciy,
                           pphat_get_hash("7") % table->capaciy,
                           pphat_get_hash("=") % table->capaciy
           );
    pphat_insert(&table,"1",1);
    pphat_insert(&table,"7",7);
    pphat_remove(table,"1");
    pphat_insert(&table,">",123);
    pphat_insert(&table,"1",69);


    pphat_print(table);

    pphat_free(table);
    return 0;
}