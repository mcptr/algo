#pragma once
#include "stack.h"


#define R0 0
#define R1 1
#define R2 2
#define R3 3


struct machine_t
{
	int max_mem;
	int *memory;

	int stack_size;
	struct stack_t *stack;

	int accumulator;
	int registers[4];
};

struct machine_t *machine_create(int max_mem, int stack_size);
void machine_destroy(struct machine_t *m);
void machine_load_program(struct machine_t *m, struct stack_t *program);
void machine_print_registers(struct machine_t *m);
void machine_dump_memory(struct machine_t *m);
