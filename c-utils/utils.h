#pragma once

#include "std.h"


#ifdef DEBUG
#define debug(fmt, ...) \
	do { fprintf(stderr, fmt, __VA_ARGS__); } while(0)
#else
#define debug(fmt, ...) 
#endif
