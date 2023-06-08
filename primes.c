// bitset.h
// Řešení IJC-DU1, příklad a), 16.3.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Výpis posledných 10-tich prvočísel od 230000000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bitset.h"

#define LIMIT 230000000


void Eratosthenes(bitset_t pole);

int main(){
    clock_t start=clock();
    bitset_create(pole,LIMIT);

    Eratosthenes(pole);

    unsigned long bit;
    int counter=10;
    unsigned long primes[10];

    for(unsigned long i=LIMIT-1; i>0;i--)
    {
        bit = bitset_getbit(pole,i);
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