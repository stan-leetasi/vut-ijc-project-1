##vut-ijc-project-1

This program implements a bitset data structure and utilizes it to find prime numbers using the Sieve of Eratosthenes algorithm.

##Build structure

- bitset.h - Definition of the bitset data structure using macros for "primes", and inline functions for "primes-i"
- bitset.c - Declaration of the bitset inline functions
- eratosthenes.c - Implementation of the Sieve of Eratosthenes algorithm
- primes.c - Prints out the last 10 prime numbers from the interval <0, 2.3x10^8>, found by the Sieve of Eratosthenes algorithm
- error.h and error.c - Prints out an error message and ends the program in case the bitset index is out of bounds

##Usage

1. To compile the program, use the provided makefile:

`make`	Compile both the regular version (primes) and the version with inline functions (primes-i)

2. To run the program:

`make run`	Executes primes and primes-i, displays the last 10 found prime numbers and the runtime of primes and primes-i.

3. Teardown

`make clean`	Deletes all intermediate and executable files

##Input and output
`make run`

229999831
229999849
229999871
229999897
229999933
229999937
229999949
229999961
229999969
229999981

Time=1.48

229999831
229999849
229999871
229999897
229999933
229999937
229999949
229999961
229999969
229999981

Time=1.46