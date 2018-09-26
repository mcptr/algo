#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>


/* NOTE:
 * There is no '999', so max product of three digits is 648 (i.e. 9 * 9 * 8)
 */


char *number_str = (
	"73167176531330624919225119674426574742355349194934"
	"96983520312774506326239578318016984801869478851843"
	"85861560789112949495459501737958331952853208805511"
	"12540698747158523863050715693290963295227443043557"
	"66896648950445244523161731856403098711121722383113"
	"62229893423380308135336276614282806444486645238749"
	"30358907296290491560440772390713810515859307960866"
	"70172427121883998797908792274921901699720888093776"
	"65727333001053367881220235421809751254540594752243"
	"52584907711670556013604839586446706324415722155397"
	"53697817977846174064955149290862569321978468622482"
	"83972241375657056057490261407972968652414535100474"
	"82166370484403199890008895243450658541227588666881"
	"16427171479924442928230863465674813919123162824586"
	"17866458359124566529476545682848912883142607690042"
	"24219022671055626321111109370544217506941658960408"
	"07198403850962455444362981230987879927244284909188"
	"84580156166097919133875499200524063689912560717606"
	"05886116467109405077541002256983155200055935729725"
	"71636269561882670428252483600823257530420752963450"
);


int main(int argc, char** argv)
{
	errno = 0;
	unsigned long span = (argc > 1 ? strtoul(argv[1], 0, 10) :  4);

	if(errno) {
		fprintf(stderr, "%s\n", strerror(errno));
		return errno;
	}


	unsigned long len = strlen(number_str);
	unsigned long i;
	unsigned long j;

	unsigned long max_product = 0;
	unsigned long total_skipped = 0;

	for(i = 0; i < len - span + 1; i++) {
		unsigned long product = 1;

		unsigned long number = 0;

		for(j = 0; j < span; j++) {
			char c = number_str[i + j];
			if(isdigit(c)) {
				int digit = (c - '0');
				// optimization: if we find 0, we can jump j-ahead
				if(digit == 0) {
					i += j;
					total_skipped += j;
					fprintf(stderr, "...Skipping %-8ld -> offset: %ld\n", j, i);
					break;
				}
				product *= digit;
				number += (c - '0') * pow(10, span - j -1);
			}
		}
		if(product > max_product) {
			max_product = product;
		}
		printf("%016ld -> %16ld\tMax: %ld\n", number, product, max_product);
	}

	printf("Span: %ld\nSkipped: %ld, Max product: %ld\n",
		   span, total_skipped, max_product);

	return 0;
}
