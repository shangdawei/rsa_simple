/******************************************************************************
	RSA Algorithm
	Reminder: ((m**e)**d) % n = m
	e: encryption, d: decryption
	Encryption: ciphertext = message**e	% n
	Decryption: (c**d == (m**e)**d == m )	% n

	RSA Key Generation
	p and q, two distrinct prime numbers
	n = pq
	fi is Euler's Totient Function
	fi(n) = fi(p) * fi(q) = (p - 1) * (q - 1) = n - (p + q - 1)

	chose e, the public key:
		- 1 < e < fi(n)
		- gcd(e, fi(n)) == 1 (i.e. e and fi(n) are coprime
	chose d, the private key:
		- d == e**-1 (mod fi(n))
		-> d is the modular multiplicative inverse of e (modulo(fi(n)))
*******************************************************************************/

typedef struct	s_rsa {

  unsigned int	n;
  unsigned int	fi;
  unsigned int	e;
  unsigned int	d;
} t_rsa;

t_rsa		rsa_algo(unsigned int p, unsigned int q)
{
  t_rsa		ret;

  ret.n = p * q;
  ret.fi = (p - 1) * (q - 1);
  
}
