#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define __STDC_FORMAT_MACROS
#include <inttypes.h>


int main(int argc, char** argv)
{
	char *ptr;
	uint64_t max = argc > 1 ? strtoull(argv[1], &ptr, 10) : 4000000;

	if(errno) {
		fprintf(stderr, strerror(errno));
		return 1;
	}

	uint64_t last = 0;
	uint64_t next = 1;
	uint64_t result = 0;

	uint64_t sum_even = 0;
	uint64_t sum_all = 0;

	printf("# Max fib number: %ld\n", max);

	while((result = last + next) <= max) {
		last = next;
		next = result;

		if(result % 2 == 0) {
			sum_even += result;
		}
		sum_all += result;

		printf(". %20" PRIu64 "\n", result);
	}

	printf("SUM of even:  %" PRIu64 "\n", sum_even);
	printf("TOTAL      :  %" PRIu64 "\n", sum_all);

	return 0;
}
