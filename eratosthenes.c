// bitset.h
// 16.3.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0
// "Sifts" the bit array through the sieve of Eratosthenes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "bitset.h"

void Eratosthenes(bitset_t array_name)
{
    unsigned long bit;
    bitset_setbit(array_name,0,1);
    bitset_setbit(array_name,1,1);
    unsigned int stop = sqrt(bitset_size(array_name));

    for(unsigned long i=2; i<=stop;i++)
    {
        bit = bitset_getbit(array_name,i);
        if(bit == 0)
        {   
            for(unsigned long j=i*2; j<bitset_size(array_name);j=j+i)
            {
                bitset_setbit(array_name,j,1);        
            }
        }
    }
}


