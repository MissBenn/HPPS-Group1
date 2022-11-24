CFLAGS=-Wall -Wextra -pedantic -std=c11

test_bits: test_bits.c bits.h
	clang -o test_bits test_bits.c $(CFLAGS)

test_numbers: test_numbers.c numbers.h
	clang -o test_numbers test_numbers.c $(CFLAGS)
