// bitset.h
// 16.3.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0
// Prints out the last 10 prime numbers from 230000000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bitset.h"

#define LIMIT 230000000


void Eratosthenes(bitset_t array_name);

int main(){
    clock_t start=clock();
    bitset_create(array_name,LIMIT);

    Eratosthenes(array_name);

    unsigned long bit;
    int counter=10;
    unsigned long primes[10];

    for(unsigned long i=LIMIT-1; i>0;i--)
    {
        bit = bitset_getbit(array_name,i);
        if(bit == 0)
        {
            counter--;
            primes[counter]=i;
            
        }
        if(counter==0){
            break;
        }   
    }
    for(int i=0;i<10;i++){
        printf("%lu\n",primes[i]);
    }

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}