// bitset.c
// 16.3.2023
// Author: Stanislav Letaši, FIT
// Compiled with: gcc 11.3.0
// Inline functions declaration, so they will conform with the O0 requirement

#include "bitset.h"

#ifdef USE_INLINE

extern inline void bitset_free(unsigned long *jmeno_pole);

extern inline unsigned long bitset_size(unsigned long *jmeno_pole);

extern inline void bitset_setbit(unsigned long *jmeno_pole, unsigned long index, unsigned long vyraz);

extern inline unsigned long bitset_getbit(unsigned long *jmeno_pole, unsigned long index);

#endif