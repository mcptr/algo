#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>


/*
 * Ideas:
 * a) 2 ** 10000 gives a number +3000 digits long. Not easy.
 * b) naive: go up to sqrt(n) and just try
 * c) aks test
 * d) simple static table of multiples
 */

int is_prime(unsigned long n)
{
	unsigned long i;
	unsigned long pivot = floor(sqrt(n));
	for(i = 2; i <= pivot; i++) {
		if(n % i == 0) {
			return 0;
		}
	}

	return 1;
}


int main(int argc, char** argv)
{
	char *ptr;
	unsigned long nth = (argc > 1 ? strtoul(argv[1], &ptr, 10) :  10001);

	if(errno) {
		fprintf(stderr, strerror(errno));
		return 1;
	}

	unsigned long counter = 0;
	unsigned long n;
	for(n = 2; n < ULONG_MAX; n++) {
		if(is_prime(n)) {
			counter++;
			if(counter == nth) {
				break;
			}
		}
	}

	printf("%ld\n", n);

	return 0;
}
