#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>


int main(int argc, char** argv)
{
	errno = 0;
	unsigned long limit = (argc > 1 ? strtol(argv[1], 0, 10) :  2000000);

	if(errno) {
		fprintf(stderr, "%s\n", strerror(errno));
		return errno;
	}

	int* primes = (int*)calloc(limit, sizeof(int));

	unsigned long i;
	unsigned long j;

	/* Sieve of Eratosthenes */

	for(i = 2; i < limit; i++) {
		if(primes[i] > -1) {
			primes[i] = i;
		}

		for(j = i * 2; j < limit; j = j + i) {
			if(j >= limit) {
				break;
			}
			primes[j] = -1;
		}
	}

	unsigned long long sum = 0;

	for(i = 2; i < limit; i++) {
		if(primes[i] != -1) {
			sum += primes[i];
		}
	}

	free(primes);
	printf("%lld\n", sum);
	return 0;
}
