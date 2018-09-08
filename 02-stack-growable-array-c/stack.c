#include <stdlib.h>
#include <stdio.h>


#ifdef DEBUG
#define LOG_DEBUG(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while(0)
#else
#define LOG_DEBUG(fmt, ...) do {} while (0)
#endif


struct stack {
	int* elements;
	int top;
	int max_size;
	int growable;
};


struct stack* stack_create(int max_size, int growable);
void stack_destroy(struct stack* s);
void stack_resize(struct stack* s, int size);
int stack_push(struct stack* s, int value);
int stack_pop(struct stack* s, int* dest);
int stack_peek(struct stack* s);
int stack_is_full(struct stack* s);
int stack_is_empty(struct stack* s);
int stack_grow(struct stack* s);
void stack_print(struct stack* s);


struct stack* stack_create(int max_size, int growable)
{
	struct stack* s = malloc(sizeof(struct stack));
	LOG_DEBUG("# CRE \t\t\t(%p, max_size: %d)\n", (void*)s, max_size);
	s->max_size = max_size;
	s->elements = malloc(max_size * sizeof(int));
	s->top = -1;
	s->growable = growable;
	return s;
}


void stack_destroy(struct stack* s)
{
	LOG_DEBUG("# DES \t\t\t(%p, max_size: %d)\n", (void*)s, s->max_size);
	free(s->elements);
}


int stack_is_full(struct stack* s)
{
	return (s->top == s->max_size - 1);
}


int stack_is_empty(struct stack* s)
{
	return (s->top < 0);
}


int stack_push(struct stack* s, int value)
{
	if(stack_is_full(s)) {
		if(!stack_grow(s)) {
			return 0;
		}
	}

	s->top += 1;
	s->elements[s->top] = value;
	LOG_DEBUG("# PSH %4d, \t\t(%p, max_size: %d, top: %d)\n", value, (void*)s, s->max_size, s->top);
	return 1;
}


int stack_pop(struct stack* s, int* dest)
{
	if(stack_is_empty(s)) {
		return 0;
	}
	
	*dest = s->elements[s->top];
	s->top--;
	LOG_DEBUG("# POP %4d \t\t(%p, max_size: %d, top: %d)\n", *dest, (void*)s, s->max_size, s->top);
	return 1;
}


int stack_peek(struct stack* s)
{
	return s->elements[s->top];
}


int stack_grow(struct stack* s)
{
	if(!s->growable) {
		return 0;
	}

	int new_size = s->max_size * 2;

	LOG_DEBUG("# GRW ++++ \t\t(%p, max_size: %d, new_size: %d)\n", (void*)s, s->max_size, new_size);
	int* elements = (int*)malloc(sizeof(int) * new_size);

	if(elements == NULL) {
		LOG_DEBUG("# ERR (%p, unable to grow, not enough memory)\n", (void*)s);
		return 0;
	}

	for(int i = 0; i < s->max_size; i++) {
		elements[i] = s->elements[i];
	}

	free(s->elements);
	s->elements = elements;
	s->max_size = new_size;
	return 1;
}


void stack_print(struct stack* s)
{
	if(stack_is_empty(s)) {
		printf("EMPTY");
	}
	for(int i = 0; i <= s->top; i++) {
		printf("%d ", s->elements[i]);
	}
	printf("\n");
}


int main()
{
	struct stack* s = stack_create(2, 1);

	for(int i = 0; i < 16; i++) {
		if(!stack_push(s, i)) {
			printf("\tFailed to push: %d\n", i);
		}
	}
	printf("PEEK: %d\n", stack_peek(s));
	stack_print(s);

	int popped;
	for(int i = 0; i < s->top / 2; i++) {
		stack_pop(s, &popped);
		printf("(peek after pop): %d\n", stack_peek(s));
	}
	stack_print(s);

	while(stack_pop(s, &popped)) {
		printf("%d ", popped);
	}
	printf("\n");

	stack_print(s);

	stack_pop(s, &popped);
	stack_pop(s, &popped);

	stack_print(s);

	stack_peek(s);
	
	stack_destroy(s);
	return 0;
}
