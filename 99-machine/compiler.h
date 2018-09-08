#pragma once
#include "stack.h"

struct stack_t *load_program(char *path);
int translate_command(const char *str);
int translate_register(const char *str);
