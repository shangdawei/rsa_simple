/*********************************************************************************
	Modular Exponentiation used for RSA
	Note that although this can be efficently done with more bits
	I constrained myself to sizeof(long long) for readability

https://en.wikipedia.org/wiki/Modular_exponentiation
**********************************************************************************/

#include "modular_exponent.h"

/*
  solves c = (a*b) mod m
  using c = ((a mod m) * (b mod m)) mod m
  the iteration is to simply with a
 */
long		modular_exponent_simple(long b, long exp, long mod)
{
  long		c = 1;

  if (mod == 1)
    return 0;
  for (long exp_prime = 1; exp_prime <= exp; ++exp_prime)
    c = (c * b) % mod;
  return c;
}

/*
  Optimized version of the above using Right to Left binary method
  Careful of overflows (I do not check for them)
 */
long		right_to_left(long long b, long long exp, long long mod)
{
  long		ret = 1;

  if (mod == 1)
    return 0;
  b = b % mod;
  while (exp > 0)
    {
      if (exp % 2 == 1) // if odd number
	ret = (ret * b) % mod;
      exp = exp >> 1;
      b = (b * b) % mod;
    }
  return ret;
}
