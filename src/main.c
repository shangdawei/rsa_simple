/*
** main.c for RSA in /home/ksa28/Kent/RSA/src
** 
** Made by Kevin Almansa
** Login   <ksa28>
** 
** Started on  Mon Jan 18 18:50:31 2016 Kevin Almansa
** Last update Mon Jan 18 18:50:43 2016 Kevin Almansa
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rsa.h"
#include "primes.h"

int		main(int ac, char **av)
{
  long		p, q;

  //Seed for random
  srandom(time(NULL));
  //Generate a list of prime numbers, used by keygen
  sieve_of_eratosthenes(atol(av[1]));
  printf("This program can accept 2 paramaters, p and q, else random values will be used");
  if (ac == 3)
    {
      p = atol(av[1]);
      q = atol(av[2]);
    }
  else
    {
      //to generate p and q
      p = random() % g_prime_list.length;
      q = random() % g_prime_list.length;
    }
  printf("P used: %ld, Q used: %ld\n", p, q);

  t_rsa		results = rsa_keygen(p, q);

  //Output Results
  printf("N: %ld\nfi(N): %ld\nChosen e: %ld\nd: %ld\n",
	 results.n, results.fi, results.e, results.d);
  return 0;
}
