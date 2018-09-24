#include <stdio.h>
#include <stdlib.h>


long count_digits(long n)
{
	long sum  = 0;
	int digit;

	printf("Number: %ld\n", n);
	while(n) {
		digit = n % 10;
		printf("  digit: %d\n", digit);
		sum += digit;
		printf("  sum: %ld\n", sum);
		n /= 10;
	}

	return sum;
}


int main(int argc, char** argv)
{
	if(argc < 2) {
		printf("Need a number.\n");
		return 1;
	}
	
	printf("Sum: %ld\n", count_digits(atol(argv[1])));

	return 0;
}
