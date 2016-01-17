#include <stdio.h>
#include <stdlib.h>
#include "primes.h"
#include "modulars.h"


//Test main for modular_exponents.c
int		main_modular_exponents(int ac, char **av, char **env)
{
  long		result_simple;
  long		result_right_to_left;
  
  result_simple = modular_exponent_simple(atol(av[1]), atol(av[2]), atol(av[3]));
  printf("Modular_exp_simple: b = %ld, exp = %ld, mod = %ld\nc = %ld \n",
	 atol(av[1]), atol(av[2]), atol(av[3]), result_simple);
  result_right_to_left = right_to_left(atol(av[1]), atol(av[2]), atol(av[3]));
  printf("Right_To_Left: b = %ld, exp = %ld, mod = %ld\nc = %ld \n",
	 atol(av[1]), atol(av[2]), atol(av[3]), result_right_to_left);
  if (result_simple == result_right_to_left)
    return 1; //true
  return 0; //false
}

//Test main for primes.c
int		main_primes(int ac, char **av, char **env)
{
  //easiest to visually verify this
  sieve_of_eratosthenes(255);
  printf("Limit used: %ld, Primes Found: %ld\n", g_prime_list.limit_used, g_prime_list.length);
  for (long i = 0; i < g_prime_list.length; i++)
    printf("%ld, ", g_prime_list.primes[i]);
  printf("\n");
  for (long i = 0; i < g_prime_list.length; i++)
    {
      if (!is_prime(g_prime_list.primes[i]))
	{
	  printf("is_prime detected non prime: %ld\n", g_prime_list.primes[i]);
	  return 0;
	}
    }
  return 1;
}

int		main(int ac, char **av, char **env)
{
  if (ac < 4)
    {
      printf("Missing paramaters, try: 4 13 497\n");
      return 1;
    }
  printf("Tests Starting...\n\n");

  if (main_modular_exponents(ac, av, env))
    puts("Success!\n");
  else
    puts("Failed\n");

  if (main_primes(ac, av, env))
    puts("Success!\n");
  else
    puts("Failed\n");

  printf("Done\n\n");
  return 0;
}
