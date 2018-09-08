#include "compiler.h"
#include "machine.h"
#include "std.h"


struct stack_t *load_program(char* path)
{
	debug("Loading program: %s\n", path);
	struct stack_t* program = stack_create(256);
	FILE *fh = fopen(path, "r");

	char word[16];
	char c;
	int i = 0;

	char* command[3][16];
	int command_id = 0;
	
	do {
		while((c = fgetc(fh)) != EOF && !isalnum(c)) { /* skip leading whitespace */ }
		do {
			word[i++] = c;
			c = fgetc(fh);
		}
		while(c != EOF && isalnum(c));

		if(c == EOF) { break;}

		word[i++] = '\0';

		strncpy((char *)&command[command_id], word, i);

		i = 0;
		command_id++;
		word[0] = '\0';

		if(command_id > 2) {
			struct inst_t *inst = mk_inst(
				translate_command((char*)command[0]),
				translate_register((char*)command[1]),
				atoi((char*)command[2]));

			snprintf(inst->comment, sizeof(inst->comment),
					 "%s %s, %s", (char*)command[0], (char*)command[1], (char*)command[2]);

			stack_push(program, inst);
			command_id = 0;
		}

	}
	while(c != EOF);

	fclose(fh);

	return program;
}


int translate_command(const char *str)
{
	int n = strlen(str);
	if(strncmp(str, "MOV", n) == 0) {
		return MOV;
	}
	else if(strncmp(str, "PUSH", n) == 0) {
		return PUSH;
	}
	else if(strncmp(str, "POP", n) == 0) {
		return POP;
	}
	else if(strncmp(str, "ADD", n) == 0) {
		return ADD;
	}
	else {
		fprintf(stderr, "Unsupported command: %s", str);
		exit(1);
	}

	return NOOP;
}


int translate_register(const char *str)
{
	int n = strlen(str);
	if(strncmp(str, "R0", n) == 0) return R0;
	else if(strncmp(str, "R1", n) == 0) return R1;
	else if(strncmp(str, "R2", n) == 0) return R2;
	else if(strncmp(str, "R3", n) == 0) return R3;

	return R0;
}
