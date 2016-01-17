#ifndef __MATH_PRIMES__
# define __MATH_PRIMES__

typedef struct  s_primes {
  unsigned long	limit_used;
  unsigned long	length;
  unsigned long	*primes;
} t_primes;


extern t_primes	g_prime_list;


unsigned long	gcd(unsigned long a, unsigned long b);
char		is_prime(long number);

//Generate a list of Primes
//sets g_prime_map to all primes found in limit
void		sieve_of_eratosthenes(long limit);

#endif
