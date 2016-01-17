#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rsa.h"
#include "primes.h"

int		main(int ac, char **av)
{
  long		p, q;

  //Seed used to increase randomness of calls to random
  srandom(time(NULL));
  
  if (ac == 3)
    {
      p = atol(av[1]);
      q = atol(av[2]);
    }
  else
    {
      //to generate p and q
      sieve_of_eratosthenes(atol(av[1]));
      p = random() % g_prime_list.length;
      q = random() % g_prime_list.length;
    }
  printf("P used: %ld, Q used: %ld\n", p, q);

  t_rsa		results = rsa_algo(p, q);

  //Output Results
  printf("N: %ld\nfi(N): %ld\nChosen e: %ld\nd: %ld\n",
	 results.n, results.fi, results.e, results.d);
  return 0;
}
