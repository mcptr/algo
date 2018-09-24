#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


#ifdef DEBUG
#define debug(fmt, ...) \
	do { fprintf(stderr, fmt, __VA_ARGS__); } while(0)
#else
#define debug(fmt, ...) 
#endif
