#ifndef __RSA__
# define __RSA__

typedef struct	s_rsa {
  long		n;
  long		fi;
  long		e;
  long		d;
} t_rsa;

t_rsa		rsa_keygen(long p, long q);

#endif
