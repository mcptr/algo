#include <stdlib.h>
#include <stdio.h>
#include <math.h>


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

	long start = pow(10, digits - 1);
	if(digits > 2) {
		start *= 9;
	}

	// hand-made optimization
	if(digits >= 5) {
		start += pow(10, digits - 2) * 9;
	}


	long end = pow(10, digits) - 1;

	printf("# Looking for palindromes in range (%ld, %ld)\n", start, end);

	int i;
	int j;
	unsigned long product = 0;

	unsigned long max_palindrome = 0;
	unsigned long product_0 = 0;
	unsigned long product_1 = 0;

	for(i = start; i < end; i++) {
		for(j = start; j < end; j++) {
			product = i * j;
			if(is_palindrome(product)) {
				if(product > max_palindrome) {
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
