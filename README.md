# RSA

## Summery
Simple RSA implementation with a detail to readabiltiy, meant to demonstrate
how the algorithm works. The C programming language was chosen for this implementation
due to the similarity in syntax to other languages.

## The Algorithm
### RSA Algorithm
### Based on: ((m**e)**d) % n = m
e : encryption, d: decryption

### Encryption: ciphertext = (message**e) % n
### Decryption: (c**d == (m**e)**d == m)  % n

### Key Generation
p and q, two distrinct prime numbers
n = pq

fi is Euler's Totient Function
fi(n) = fi(p) * fi(q) = (p - 1) * (q - 1) = n - (p + q - 1)

chose e, the public key so that:
      1. 1 < e < fi(n)
      2. gcd(e, fi(n)) == 1 (i.e. e and fi(n) are coprime

chose d, the private key so that:
      1. d == (e **-1) % fi(n)
      ...d is the modular multiplicative inverse of e modulo(fi(n))

## Compile
Create test binary
```bash
make tests
```

Recompile tests
```bash
make re-tests
```

Create RSA binary
```bash
make
```

Remove object files created durring build
```bash
make clean
```

Remove object files and binaries
```bash
make fclean
```

## Directory Structure

| Function name		| Description					|
| -------------		| -----------					|
| src			| Folder containing all the C source files	|
| include		| Folder containing all the C include files	|
| Makefile		| Configuration file for *make* command		|

## Files
### primes
All functions related to the generation and verification of primes numbers.

Contains one global variable: g_prime_list used to store a list of prime numbers
generated by sieve_of_eratosthenes

| Function name	      	 | Description							|
| -------------		 | -----------							|
| gcd			 | greatest common denominator					|
| is_prime		 | verifies if number is prime					|
| sieve_of_eratosthenes	 | Generates a list of prime numbers, stored in g_prime_list	|

### modular_exponent
All functions related to modular exponentiation used by the RSA algorithm.

| Function name		 	 | Description					|
| -------------		 	 | -----------					|
| modular_exponent_simple	 | simple implementation of modular exponent	|
| right_to_left			 | optimized implementation of modular exponent	|

### rsa
Contains the actual RSA algorithm

| Function name			| Description					|
| -------------			| -----------					|
| rsa_algo			| implementation of the RSA algorithm		|