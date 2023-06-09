#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pphat.h"

int main(void) {
    srand(time(NULL));


    PpHat* table = pphat_create();

    pphat_insert(&table,"0",rand() % 255);
    pphat_insert(&table,"1",rand() % 255);
    pphat_insert(&table,"2",rand() % 255);
    pphat_insert(&table,"3",rand() % 255);
    pphat_insert(&table,"4",rand() % 255);
    pphat_insert(&table,"5",rand() % 255);
    pphat_insert(&table,"6",rand() % 255);

    pphat_insert(&table,"1",69);
    pphat_print(table);


    pphat_free(table);
    return 0;
}