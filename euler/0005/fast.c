#include "fast.h"
#include "std.h"


void factorize(int n, struct vector_t* vec)
{
	int f = 2;
	while(n % 2 == 0) {
		vector_push(vec, 2);
		n /= 2;
	}

	f = 3;
	while(n != 1) {
		while(n % f == 0) {
			vector_push(vec, f);
			n /= f;
		}
		f += 2;
	}
}

void merge_factors(struct vector_t *all_factors, const struct vector_t *new_factors)
{
	if(!all_factors->size) {
		vector_cat(all_factors, new_factors);
		return;
	}

	unsigned int i;
	for(i = 0; i < new_factors->size; i++) {
		/* they are sorted */
		if(i && (new_factors->array[i] == new_factors->array[i - 1])) {
			continue;
		}
		int value = new_factors->array[i];
		int diff = (vector_count(new_factors, value) - vector_count(all_factors, value));

		if(diff > 0) {
			int j;
			for(j = 0; j < diff; j++) {
				vector_push(all_factors, value);
			}
		}
	}
}


void solution_fast(unsigned int n)
{
	struct vector_t *all_factors = vector_create(128);

	unsigned int i;
	for(i = 1; i <= n; i++) {
		struct vector_t *factors = vector_create(32);
		factorize(i, factors);
		merge_factors(all_factors, factors);
		vector_destroy(&factors);
	}

	vector_print(all_factors);
	unsigned long long product = 1;

	for(i = 0; i < all_factors->size; i++) {
		product *= all_factors->array[i];
	}

	printf("Product: %lld\n", product);
}
