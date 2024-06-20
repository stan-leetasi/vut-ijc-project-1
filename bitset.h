// bitset.h
// 16.3.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0
// Bit array data structure definition

#include <assert.h>
#include <stdlib.h>
#include "error.h"
#ifndef FILES_BITSET_H
#define FILES_BITSET_H 1

typedef unsigned long *bitset_t;

typedef unsigned long bitset_index_t;

#define long_bits (8 * sizeof(unsigned long))

// defines and zeroes out the array_name variable
#define bitset_create(array_name, array_size)                                                     \
    static_assert(array_size > 0 && array_size < 250000000, "ERR in bitset_create: array size must be > 0"); \
    unsigned long array_name[((array_size - 1) / (long_bits)) + 2] = {0};                         \
    array_name[0] = array_size

// defines the array_name variable in a way to make it compatible with an array created by bitset_create, but the array will be allocated dynamically
#define bitset_alloc(array_name, array_size)                                                                                 \
    assert(array_size > 0 && array_size < 250000000 && "ERR in bitset_alloc: array size must be > 0 && array_size < 250000000"); \
    bitset_t array_name = calloc((((array_size - 1) / (long_bits)) + 2), sizeof(unsigned long));                             \
    assert(array_name != NULL && "ERR in bitset_alloc: memory allocation failed");                                                 \
    array_name[0] = array_size

#ifndef USE_INLINE

// frees memory of the dynamically allocated array
#define bitset_free(array_name) free(array_name)

// returns the declared array_size of an array in bits
#define bitset_size(array_name) array_name[0]

// sets bit in array_name on the index position to a bit_value
#define bitset_setbit(array_name, index, bit_value)                                                                                                                       \
    do                                                                                                                                                                \
    {                                                                                                                                                                 \
        if ((index) >= array_name[0])                                                                                                                                 \
        {                                                                                                                                                             \
            error_exit((index), array_name[0]);                                                                                                                       \
        }                                                                                                                                                             \
        unsigned long value = array_name[(index) / (long_bits) + 1];                                                                                                  \
        (bit_value) > (0) ? (value = ((1ul << ((long_bits) - (index % long_bits) - 1)) | value)) : (value = (~(1ul << ((long_bits) - (index % long_bits) - 1)) & value)); \
        array_name[(index) / (long_bits) + 1] = value;                                                                                                                \
    } while (0)

// returns the bit bit_value from array_name on position index
#define bitset_getbit(array_name, index) ((index < array_name[0]) ? ((array_name[(index) / (long_bits) + 1] >> ((long_bits) - (index % long_bits) - 1)) & 1) : (error_exit(index, array_name[0])))

#endif
#ifdef USE_INLINE

inline void bitset_free(unsigned long *array_name){
    free(array_name);
}

inline unsigned long bitset_size(unsigned long *array_name){
    return array_name[0];
}

inline void bitset_setbit(unsigned long *array_name, unsigned long index, unsigned long bit_value){                                                                                                                                                                                                                                                                                                              
    if ((index) >= array_name[0])                                                                                                                                 
    {                                                                                                                                                             
        error_exit((index), array_name[0]);                                                                                                                       
    }                                                                                                                                                             
    unsigned long value = array_name[(index) / (long_bits) + 1];                                                                                                  
    if(bit_value > 0){
        value = ((1ul << ((long_bits) - (index % long_bits) - 1)) | value);

    }
    else{
        value = (~(1ul << ((long_bits) - (index % long_bits) - 1)) & value);                                                                                                                
    }
    array_name[(index) / (long_bits) + 1] = value;
}

inline unsigned long bitset_getbit(unsigned long *array_name, unsigned long index){
    if (index < array_name[0]){
        return((array_name[(index) / (long_bits) + 1] >> ((long_bits) - (index % long_bits) - 1)) & 1);
    }
    else{
        error_exit(index, array_name[0]);
        return 1;
    }
}

#endif
#endif
