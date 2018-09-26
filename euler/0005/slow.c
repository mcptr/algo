#include "slow.h"
#include "std.h"


void solution_slow()
{
	unsigned long found = 0;
	unsigned long i = 2520;

	while(!found && i < ULONG_MAX) {
		if(i % 20 == 0 && /* 10, 5, 4, 2 */
		   i % 19 == 0 &&
		   i % 18 == 0 && /* 9, 6, 3 */
		   i % 17 == 0 &&
		   i % 16 == 0 && /* 8, 4 */
		   i % 15 == 0 && /* 5, 3 */
		   i % 14 == 0 && /* 7, 2 */
		   i % 13 == 0 &&
		   i % 12 == 0 && /* 6, 4, 3, 2 */
		   i % 11 == 0)
		{
			found = i;
		}

		i++;
	}

	printf("Found: %ld\n", found);

	// check it:
	int divisor;
	for(divisor = 2; divisor <= 20; divisor++) {
		assert(found % divisor == 0);
	}
}
