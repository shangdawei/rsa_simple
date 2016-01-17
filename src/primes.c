/******************************************************************************
	Functions for generation of prime and corpime numbers
*******************************************************************************/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "primes.h"

t_primes	g_prime_list = { 0 };

/*
  largest number that can devide two numbers
 */
unsigned long	gcd(unsigned long a, unsigned long b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

/*
  simple memory effecient way to determine if number is prime
 */
char		is_prime(long number)
{
  if (number < 2)
    return 0;
  for (long long i = 2; i < (int)round(sqrtl(number)); i++)
    {
      if (number % i == 0)
	return 0;
    }
  return 1;
}

//could be optimized by segmented sieve
void		sieve_of_eratosthenes(long limit)
{
  char		*primes;
  long		prime_optimization = (long)floor(sqrtl(limit));
  long		prime_count = limit - 2; //0 and 1 are not primes, so -2

  primes = malloc(limit * sizeof(char));
  memset(primes, 1, limit * sizeof(char));

  //find primes
  primes[0] = 0;
  primes[1] = 0;
  for (unsigned long i = 2; i < prime_optimization; i++)
    {
      if (primes[i])
	{
	  for (unsigned long j = i * i; j < limit; j += i)
	    {
	      if (primes[j])
		{
		  primes[j] = 0;
		  prime_count--;
		}
	    }
	}
    }

  //set primes
  if (g_prime_list.length != 0)
    free(g_prime_list.primes);
  g_prime_list.limit_used = limit;
  g_prime_list.length = prime_count;
  g_prime_list.primes = malloc(prime_count * sizeof(unsigned long));
  int j = 0;
  for (int i = 0; i < limit; i++)
    {
      if (primes[i])
	{
	  g_prime_list.primes[j] = i;
	  j++;
	}
    }
  free(primes);
}
