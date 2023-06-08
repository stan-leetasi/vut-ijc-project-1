// bitset.c
// Řešení IJC-DU1, příklad a), 16.3.2023
// Autor: Stanislav Letaši, FIT
// Přeloženo: gcc 11.3.0
// Deklaracia inline funkcií aby splňovali požiadavku O0

#include "bitset.h"

#ifdef USE_INLINE

extern inline void bitset_free(unsigned long *jmeno_pole);

extern inline unsigned long bitset_size(unsigned long *jmeno_pole);

extern inline void bitset_setbit(unsigned long *jmeno_pole, unsigned long index, unsigned long vyraz);

extern inline unsigned long bitset_getbit(unsigned long *jmeno_pole, unsigned long index);

#endif