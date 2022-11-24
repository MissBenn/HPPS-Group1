CFLAGS=-Wall -Wextra -pedantic -std=c11

test_bits: test_bits.c bits.h
	gcc -o test_bits test_bits.c $(CFLAGS)