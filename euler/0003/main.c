#include <stdlib.h>
#include <stdio.h>


int is_prime(unsigned long n)
/* naive */
{
	if(n < 2) {
		return 0;
	}
	unsigned long max = n / 2;
	unsigned long i;
	for(i = 2; i <= max; i++) {
		if(n % i == 0)
			return 0;
	}

	return 1;
}


long next_prime(unsigned long bottom)
/* naive prime gen. */
{
	long i = 1;
	long n = bottom;

	while(i < 70000000) { // proven to be bounded...
		n = bottom + i;
		if(is_prime(n)) {
			return n;
		}

		i++;
	}

	return -1;
}


int main(int argc, char *argv[])
{
	char *ptr;
	unsigned long number = (argc > 1 ? strtoul(argv[1], &ptr, 10) :  600851475143);

	long prime = 2;

	while(number > 1) {
		if(number % prime == 0) {
			number /= prime;
			printf("%ld, ", prime);
		}
		else {
			prime = next_prime(prime);
		}
	}

	printf("\n");

	return 0;
}
