# pp-hat
short for personal portable hash table, its a hash table c header library implementation         
**dont use it**

## Functions
    * PpHat* pphat_create();  
    * void   pphat_free(PpHat* table);   
    * void   pphat_insert(PpHat** table,char* name,int value);   
    * void   pphat_print(const PpHat* table);  
    * int    pphat_get(const PpHat* table,const char* key);  
    * bool   pphat_contains(const PpHat* table,const char* key);  
## Run
for examples check out [example.c](./example.c)
```
    $ ./run.sh
```
