#include "std.h"
#include "machine.h"
#include "stack.h"
#include "compiler.h"


void process(struct machine_t *machine)
{
	debug(">>> Starting machine: %p\n", (void*)machine);
	machine_dump_memory(machine);
	while(!stack_is_empty(machine->stack)) {
		struct inst_t *i = stack_pop(machine->stack);
		debug("\n>>> %s # %d (arg0: %d, arg1: %d)\n", i->comment, i->code, i->args[0], i->args[1]);

		switch(i->code) {
		case MOV:
			machine->registers[i->args[0]] = i->args[1];
			break;
		case ADD:
			machine->accumulator = (
				machine->registers[i->args[0]] +
				machine->registers[i->args[1]]);
			break;
		}
		machine_dump_memory(machine);

		free(i);
		sleep(1);
	}

	machine_dump_memory(machine);
}


int main(int argc, char** argv)
{
	struct machine_t *machine = machine_create(64, 32);

	struct stack_t *program = (argc > 1 ? load_program(argv[1]) : stack_create(32));

	machine_load_program(machine, program);
	process(machine);

	stack_destroy(program);
	
	machine_destroy(machine);
	return 0;
}
