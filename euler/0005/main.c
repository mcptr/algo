#include "slow.h"
#include "fast.h"
#include "std.h"


int main(int argc, char** argv)
{
	unsigned long n = (argc > 1 ? strtoul(argv[1], 0, 10) :  20);
	solution_fast(n);

	return 0;
}
