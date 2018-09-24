#include "conversions.h"
#include <stdio.h>



long decimal_to_binary(long n)
{
	long binary_value = 0;
	long reminder = 0;
	long base = 1;

	while(n) {
		reminder = n % 2;
		binary_value = binary_value + reminder * base;
		n /= 2;
		base *= 10;
	}

	return binary_value;
}


long binary_to_decimal(long n)
{
	long decimal_value = 0;
	long reminder = 0;
	long base = 1;

	while(n) {
		reminder = n % 10;
		decimal_value = decimal_value + reminder * base;
		n /= 10;
		base *= 2;
	}

	return decimal_value;
}


long binary_to_octal(long binary)
{
	long octal = 0;
	int reminder = 0;
	long base = 1;

	long decimal = binary_to_decimal(binary);
	
	while(decimal > 0) {
		reminder = decimal % 8; 
		octal = octal + reminder * base;
		decimal /= 8;
		base *= 10;
	}

	return octal;
}
