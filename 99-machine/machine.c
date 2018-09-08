#include "std.h"
#include "machine.h"


struct machine_t *machine_create(int max_mem, int stack_size)
{
	struct machine_t *machine = malloc(sizeof(struct machine_t));
	machine->max_mem = max_mem;
	machine->memory = malloc(max_mem * sizeof(int));
	machine->stack = stack_create(stack_size);
	machine->stack_size = stack_size;
	machine->accumulator = 0;
	return machine;
}


void machine_destroy(struct machine_t *m)
{
	stack_destroy(m->stack);
	free(m->memory);
	free(m);
}


void machine_load_program(struct machine_t *m, struct stack_t *program)
{
	stack_destroy(m->stack);
	m->stack = stack_create(m->stack_size);
	while(!stack_is_empty(program)) {
		stack_push(m->stack, stack_pop(program));
	}
}


void machine_print_registers(struct machine_t *m)
{
	printf("# R0=%-4d R1=%-4d R2=%-4d R3=%-4d ACC=%d\n",
		   m->registers[0],
		   m->registers[1],
		   m->registers[2],
		   m->registers[3],
		   m->accumulator);
}

void machine_dump_memory(struct machine_t *m)
{
	machine_print_registers(m);
	printf("# ");
	for(int i = 0; i < m->max_mem; i++) {
		printf("%-2d ", m->memory[i]);
		if(i && (i + 1) % 32 == 0) {
			if(i < m->max_mem - 1)
				printf("\n# ");
		}
	}
	printf("\n");
}
