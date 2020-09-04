CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<