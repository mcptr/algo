#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * Quick benchmarks show that is_palindrome_naive()
 * is faster than is_palindrome(). Maybe because
 * naive exits early in non-palindrome case (although it does
 * the same amount of divisions to fill the array).
 */

int is_palindrome_naive(unsigned long n)
{
	int digits[64];
	int length = 0;

	// make an array of digits
	while(n) {
		digits[length] = n % 10;
		length++;
		n /= 10;
	}

	// check if it's a palindrome
	int i;
	for(i = 0; i <= length - 1; i++, length--) {
		if(digits[i] != digits[length - 1]) {
			return 0;
		}
	}

	return 1;
}


int is_palindrome(unsigned long n)
{
	unsigned long original = n;
	unsigned long reversed = 0;
	unsigned long remainder = 0;

	while(n) {
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	return (original == reversed);
}


int main(int argc, char** argv)
{
	char *ptr;
	unsigned long digits = (argc > 1 ? strtoul(argv[1], &ptr, 10) :  3);

	if(digits < 1) {
		fprintf(stderr, "Invalid amount of digits: %ld\n", digits);
		return -1;
	}

	unsigned long start = pow(10, digits - 1);
	unsigned long end = pow(10, digits) - 1;

	printf("# Looking for palindromes in range (%ld, %ld)\n", start, end);

	unsigned long i;
	unsigned long j;
	unsigned long product = 0;

	unsigned long max_palindrome = 0;
	unsigned long product_0 = 0;
	unsigned long product_1 = 0;

	unsigned long min_product = 0;

	/* the outer loop starts from top, the inner from bottom.
	 * if we get to the largest known factor within inner/bottom loop range
	 * it means that (i * end) can't get greater than known max_palindrome
	 *
	 */
	for(i = end; i >= start; i--) {

		if((max_palindrome && i <= min_product))
			break;

		for(j = start; j <= end; j++) {
			product = i * j;
			if(is_palindrome_naive(product)) {
				printf("# %ld * %ld = %16ld\tMAX: %ld, (min product: %ld)\n",
					   i, j, product, max_palindrome, min_product);
				if(product > max_palindrome) {
					min_product = j;
					max_palindrome = product;
					product_0 = i;
					product_1 = j;
				}
			}

		}
	}

	printf("Digits: %ld, Palindrome: %ld (%ld * %ld)\n", digits, max_palindrome, product_0, product_1);


	return 0;
}
