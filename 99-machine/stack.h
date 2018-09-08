#pragma once

#include "inst.h"


struct stack_t {
	int top;
	int max_size;
	struct inst_t **elements;
};


struct stack_t * stack_create(int max_size);
void stack_destroy(struct stack_t *s);
void stack_resize(struct stack_t *s, int size);
int stack_push(struct stack_t *s, struct inst_t *value);
struct inst_t* stack_pop(struct stack_t *s);
int stack_is_full(struct stack_t *s);
int stack_is_empty(struct stack_t *s);
