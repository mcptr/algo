#pragma once

struct vector_t
{
	int *array;
	unsigned int max_size;
	unsigned int size;
};


struct vector_t *vector_create(int max_size);
void vector_destroy(struct vector_t **vec);
void vector_push(struct vector_t *vec, int n);
void vector_cat(struct vector_t *dest, const struct vector_t *src);
int vector_count(const struct vector_t *vec, int n);
void vector_print(const struct vector_t *vec);
