#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void run(long max, long incr, long* sum_even, long* sum_odd)
{
	for(long i = incr; i <= max; i += incr) {
		if(i % 2 == 0) {
			*sum_even += i;
			printf("e: %016ld\t\t%016ld\t+%s\n", i, *sum_even, (*sum_even > *sum_odd) ? "even" : "odd");
		}
		else {
			*sum_odd += i;
			printf("o: %016ld\t\t%016ld\t+%s\n", i, *sum_odd, (*sum_even > *sum_odd) ? "even" : "odd");
		}
	}
}


int main(int argc, char** argv)
{
	char *ptr;
	unsigned long max = LLONG_MAX;
	if(argc > 1) {
		max = strtoul(argv[1], &ptr, 10);
	}

	long incr = 1;
	if(argc > 2) {
		incr = strtoul(argv[2], &ptr, 10);
	}

	long sum_even = 0, sum_odd = 0;
	run(max, incr, &sum_even, &sum_odd);

	printf("Sum even: %ld\n", sum_even);
	printf("Sum odd : %ld\n", sum_odd);

	return 0;
}
