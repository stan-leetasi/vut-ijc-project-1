// bitset.h
// Řešení IJC-DU1, příklad a), 16.3.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Prejdenie bitového poľa Eratosthenovim sitom

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "bitset.h"

void Eratosthenes(bitset_t pole)
{
    unsigned long bit;
    bitset_setbit(pole,0,1);
    bitset_setbit(pole,1,1);
    unsigned int stop = sqrt(bitset_size(pole));

    for(unsigned long i=2; i<=stop;i++)
    {
        bit = bitset_getbit(pole,i);
        if(bit == 0)
        {   
            for(unsigned long j=i*2; j<bitset_size(pole);j=j+i)
            {
                bitset_setbit(pole,j,1);        
            }
        }
    }
}


