// error.c
// Řešení IJC-DU1, příklad a), 16.3.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Modul na výpis chybových hlášok
#include <stdio.h>
#include <stdlib.h>
typedef unsigned long bitset_index_t;

void error_exit(bitset_index_t index, unsigned long mez)
{
    printf("bitset_getbit: Index %lu mimo rozsah 0..%lu",index, mez);
    exit(1);
}
    