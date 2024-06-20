CC=gcc
CFLAGS= -g -Wextra -Wall -pedantic -std=c11 -O0 -Wno-unused-value
default: primes primes-i

primes: primes.o eratosthenes.o error.o
		$(CC) $(CFLAGS) -o primes primes.o error.o eratosthenes.o -lm

primes.o: primes.c bitset.h
		$(CC) $(CFLAGS) -c primes.c

error.o: error.c error.h bitset.h
		$(CC) $(CFLAGS) -c error.c

eratosthenes.o: eratosthenes.c bitset.h
		$(CC) $(CFLAGS) -c eratosthenes.c

primes-i: primes-i.o eratosthenes-i.o error-i.o bitset.o
		$(CC) $(CFLAGS) -DUSE_INLINE -o primes-i primes-i.o error-i.o eratosthenes-i.o bitset.o -lm

primes-i.o: primes.c bitset.h 
		$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

error-i.o: error.c error.h bitset.h
		$(CC) $(CFLAGS) -DUSE_INLINE -c error.c -o error-i.o

eratosthenes-i.o: eratosthenes.c bitset.h
		$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o

bitset.o: bitset.h bitset.c
		$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset.o

clean:
		rm -f *.o primes primes-i

run: primes primes-i
		ulimit -s 50000; ./primes; ./primes-i
