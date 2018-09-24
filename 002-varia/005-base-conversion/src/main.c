#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>


#include "conversions.h"


int main(int argc, char** argv)
{
	if(argc < 2) {
		printf("Need a number.\n");
		return 1;
	}

	char *ptr;
	unsigned long decimal = strtoul(argv[1], &ptr, 10);

	if(errno) {
		fprintf(stderr, strerror(errno));
		return 1;
	}

	printf("inp: %ld\n", decimal);

	long bin = decimal_to_binary(decimal);
	printf("bin: %ld\n", bin);

	decimal = binary_to_decimal(bin);
	printf("dec: %ld\n", decimal);

	long octal = binary_to_octal(bin);
	printf("oct: %ld\n", octal);

	return 0;
}
