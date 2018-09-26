#include "vector.h"
#include "std.h"


struct vector_t *vector_create(int max_size)
{
	struct vector_t *vec = (struct vector_t*) malloc(sizeof(struct vector_t));
	vec->array = (int*) malloc(max_size * sizeof(int));
	vec->max_size = max_size;
	vec->size = 0;
	return vec;
}

void vector_destroy(struct vector_t **vec)
{
	free((*vec)->array);
	free(*vec);
	*vec = NULL;
}

void vector_push(struct vector_t *vec, int n)
{
	assert(vec->size < vec->max_size);
	vec->array[vec->size++] = n;
}

int vector_count(const struct vector_t *vec, int n)
{
	unsigned int total = 0;

	unsigned int i = 0;
	for(i = 0; i < vec->size; i++) {
		if(vec->array[i] == n) {
			total++;
		}
	}

	return total;
}

void vector_cat(struct vector_t *dest, const struct vector_t *src)
{
	assert((dest->max_size - dest->size) > src->size);

	unsigned int i;
	for(i = 0; i < src->size; i++) {
		vector_push(dest, src->array[i]);
	}
}

void vector_print(const struct vector_t *vec)
{
	unsigned int i;
	printf("%p [", (void*) vec);
	for(i = 0; i < vec->size; i++) {
		printf("%d, ", vec->array[i]);
	}
	printf("]\n");

}
