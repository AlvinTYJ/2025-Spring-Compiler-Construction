#ifndef COMPILER_COMMON_H
#define COMPILER_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

/* Add what you need */
typedef struct {
    char *type;
    int i_val;
    float f_val;
    char *s_val;
    int local_idx;
} ExprVal;

// Declare the CODEGEN function
void CODEGEN(const char *format, ...);

#endif /* COMPILER_COMMON_H */