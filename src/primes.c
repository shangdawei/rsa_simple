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
long	gcd(long a, long b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

/*
  simple memory effecient way to determine if number is prime
  not 100% sure about the long return for roundl
*/
char		is_prime(long number)
{
  if (number < 2)
    return 0;
  for (long i = 2; i < (long)lround(sqrtl(number)) + 1; i++)
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
  long		prime_optimization = (long)lround(sqrtl(limit)) + 1;
  long		prime_count = limit - 2; //0 and 1 are not primes, so -2

  primes = malloc(limit * sizeof(char));
  memset(primes, 1, limit * sizeof(char));

  //find primes
  primes[0] = 0;
  primes[1] = 0;
  for (long i = 2; i < prime_optimization; i++)
    {
      if (primes[i])
	{
	  for (long j = i * i; j < limit; j += i)
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
  g_prime_list.primes = malloc(prime_count * sizeof(long));
  long j = 0;
  for (long i = 0; i < limit; i++)
    {
      if (primes[i])
	{
	  g_prime_list.primes[j] = i;
	  j++;
	}
    }
  free(primes);
}
