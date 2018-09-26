#pragma once

#include "vector.h"


void factorize(int n, struct vector_t *factors);
void merge_factors(struct vector_t *all_factors, const struct vector_t *new_factors);
void solution_fast(unsigned int n);
