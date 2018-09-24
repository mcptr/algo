#include "inst.h"
#include "std.h"


struct inst_t *mk_inst(int code, int arg0, int arg1)
{
	struct inst_t *inst = malloc(sizeof(struct inst_t));
	inst->code = code;
	inst->args[0] = arg0;
	inst->args[1] = arg1;
	inst->comment[0] = '\0';

	return inst;
}
