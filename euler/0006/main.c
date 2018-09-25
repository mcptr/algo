#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


/* Overflows. */

int main(int argc, char** argv)
{
	char *ptr;
	unsigned long max = (argc > 1 ? strtoul(argv[1], &ptr, 10) :  100);

	printf("Range: 1 - %ld\n", max);

	unsigned long long sum = 0;
	unsigned long long sum_of_squares = 0;

	unsigned long i;
	for(i = 1; i <= max; i++) {
		sum += i;
		sum_of_squares += i * i;
	}

	// The problem seems to be worded the other way around.
	unsigned long long result = (sum * sum) - sum_of_squares;

	printf("Sum: %lld, sum squared: %lld\n", sum, (sum * sum));
	printf("Sum of squares: %lld\nDifference: %lld\n",
		   sum_of_squares, result);


	return 0;
}
