// error.c
// 16.3.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0
// Module that prints out error messages

#include <stdio.h>
#include <stdlib.h>
typedef unsigned long bitset_index_t;

unsigned long error_exit(bitset_index_t index, unsigned long array_end)
{
    printf("bitset_getbit: Index %lu out of range 0..%lu",index, array_end);
    exit(1);
}
    