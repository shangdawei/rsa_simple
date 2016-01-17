RM		= rm -f
CC		= gcc

NAME		= rsa
NAME_TESTS	= rsa_tests

CFLAGS		= -Iinclude/ -W -Wall -Wextra -O3 -march=native -ggdb3
LDFLAGS		= -lm

SRCS_TEST	= src/modular_exponent.c		\
		  src/primes.c				\
		  src/rsa.c				\
		  src/tests_main.c
OBJS_TEST	= $(SRCS_TEST:.c=.o)

SRCS		= src/modular_exponent.c		\
		  src/primes.c				\
		  src/rsa.c				\
		  src/main.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

tests: $(OBJS_TEST)
	$(CC) -o $(NAME_TESTS) $(OBJS_TEST) $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(OBJS_TEST)

fclean: clean
	$(RM) $(NAME) $(NAME_TESTS)

re: fclean all

re-tests: fclean tests