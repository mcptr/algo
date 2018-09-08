#pragma once

#define NOOP  0x0000
#define PRINT 0x0010
#define MOV   0x0100
#define PUSH  0x0111
#define POP   0x0112
#define ADD   0x0201
#define JMP   0x0200


struct inst_t
{
	int code;
	int args[2];
	char comment[32];
};

struct inst_t *mk_inst(int code, int arg0, int arg1);
