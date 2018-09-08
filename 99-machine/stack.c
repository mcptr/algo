#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"
#include "inst.h"


struct stack_t *stack_create(int max_size)
{
	struct stack_t *s = malloc(sizeof(struct stack_t));
	s->max_size = max_size;
	s->elements = malloc(max_size * sizeof(struct inst_t));
	s->top = -1;
	return s;
}


void stack_destroy(struct stack_t *s)
{
	free(s->elements);
}


int stack_is_full(struct stack_t *s)
{
	return (s->top == s->max_size - 1);
}


int stack_is_empty(struct stack_t *s)
{
	return (s->top < 0);
}


int stack_push(struct stack_t *s, struct inst_t *value)
{
	if(stack_is_full(s)) {
		return 0;
	}

	s->top += 1;
	s->elements[s->top] = value;
	return 1;
}


struct inst_t *stack_pop(struct stack_t *s)
{
	assert(!stack_is_empty(s));
	
	struct inst_t* value = s->elements[s->top];
	s->top--;
	return value;
}
