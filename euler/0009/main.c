#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


int is_pythagorean_triplet(int a, int b, int c)
{
	return (a * a) + (b * b) == (c * c);
}

int main(int argc, char** argv)
{
	errno = 0;
	long sum = (argc > 1 ? strtol(argv[1], 0, 10) :  1000);

	if(errno) {
		fprintf(stderr, "%s\n", strerror(errno));
		return errno;
	}

	int a, b, c;

	for(a = 1; a <= sum; a++) {
		for(b = 1; b <= sum; b++) {
			c = sum - (a + b);
			if(is_pythagorean_triplet(a, b, sum - (a + b))) {
				printf("a = %d, b = %d, c = %d\n", a, b, c);
				return 0;
			}
		}
	}

	return 0;
}
