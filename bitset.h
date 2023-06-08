// bitset.h
// Řešení IJC-DU1, příklad a), 16.3.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Definícia dátovej štruktúry bitové pole

#include <assert.h>
#ifndef FILES_BITSET_H
#define FILES_BITSET_H 1

typedef unsigned long *bitset_t;

typedef unsigned long bitset_index_t;

#define long_bits (8 * sizeof(unsigned long))

// definuje a _nuluje_ proměnnou jmeno_pole
#define bitset_create(jmeno_pole, velikost)                                                     \
    static_assert(velikost > 0 && velikost < 250000000, "bitset_create: velkost musi byt > 0"); \
    unsigned long jmeno_pole[((velikost - 1) / (long_bits)) + 2] = {0};                         \
    jmeno_pole[0] = velikost

// definuje proměnnou jmeno_pole tak, aby byla kompatibilní s polem vytvořeným pomocí bitset_create, ale pole bude alokováno dynamicky.
#define bitset_alloc(jmeno_pole, velikost)                                                                                 \
    assert(velikost > 0 && velikost < 250000000 && "bitset_alloc: velkost musi byt velikost > 0 && velikost < 250000000"); \
    bitset_t jmeno_pole = calloc((((velikost - 1) / (long_bits)) + 2), sizeof(unsigned long));                             \
    assert(jmeno_pole != NULL && "bitset_alloc: alokacia pamate zlyhala");                                                 \
    jmeno_pole[0] = velikost

#ifndef USE_INLINE

// uvolní paměť dynamicky (bitset_alloc) alokovaného pole
#define bitset_free(jmeno_pole) free(jmeno_pole)

// vrátí deklarovanou velikost pole v bitech (uloženou v poli)
#define bitset_size(jmeno_pole) jmeno_pole[0]

// nastaví zadaný bit v poli na hodnotu zadanou výrazem (0 alebo 1)
#define bitset_setbit(jmeno_pole, index, vyraz)                                                                                                                       \
    do                                                                                                                                                                \
    {                                                                                                                                                                 \
        if (index < 0)                                                                                                                                                \
        {                                                                                                                                                             \
            error_exit(index, jmeno_pole[0]);                                                                                                                         \
        }                                                                                                                                                             \
        if ((index) >= jmeno_pole[0])                                                                                                                                 \
        {                                                                                                                                                             \
            error_exit((index), jmeno_pole[0]);                                                                                                                       \
        }                                                                                                                                                             \
        unsigned long value = jmeno_pole[(index) / (long_bits) + 1];                                                                                                  \
        (vyraz) > (0) ? (value = ((1ul << ((long_bits) - (index % long_bits) - 1)) | value)) : (value = (~(1ul << ((long_bits) - (index % long_bits) - 1)) & value)); \
        jmeno_pole[(index) / (long_bits) + 1] = value;                                                                                                                \
    } while (0)

// získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1
#define bitset_getbit(jmeno_pole, index) ((index >= 0) && ((index < jmeno_pole[0])) ? ((jmeno_pole[(index) / (long_bits) + 1] >> ((long_bits) - (index % long_bits) - 1)) & 1) : (error_exit(index, jmeno_pole[0])))

unsigned long error_exit(bitset_index_t index, unsigned long mez);

#endif

#ifdef USE_INLINE

inline void bitset_free(unsigned long *jmeno_pole){
    free(jmeno_pole);
}

inline unsigned long bitset_size(unsigned long *jmeno_pole){
    return jmeno_pole[0];
}

inline void bitset_setbit(unsigned long *jmeno_pole, unsigned long index, unsigned long vyraz){                                                                                                                                                                 \
    if (index < 0)                                                                                                                                                
    {                                                                                                                                                             
        error_exit(index, jmeno_pole[0]);                                                                                                                         
    }                                                                                                                                                             
    if ((index) >= jmeno_pole[0])                                                                                                                                 
    {                                                                                                                                                             
        error_exit((index), jmeno_pole[0]);                                                                                                                       
    }                                                                                                                                                             
    unsigned long value = jmeno_pole[(index) / (long_bits) + 1];                                                                                                  
    if(vyraz > 0){
        value = ((1ul << ((long_bits) - (index % long_bits) - 1)) | value);

    }
    else{
        value = (~(1ul << ((long_bits) - (index % long_bits) - 1)) & value);                                                                                                                
    }
    jmeno_pole[(index) / (long_bits) + 1] = value;
}

inline unsigned long bitset_getbit(unsigned long *jmeno_pole, unsigned long index){
    if (index >= 0 && index < jmeno_pole[0]){
    return((jmeno_pole[(index) / (long_bits) + 1] >> ((long_bits) - (index % long_bits) - 1)) & 1);
    }
    else{
        error_exit(index, jmeno_pole[0]);
    } 

} 

#endif
#endif
