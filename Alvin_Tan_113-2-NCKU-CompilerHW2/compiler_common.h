#ifndef COMPILER_COMMON_H
#define COMPILER_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Add what you need */
typedef struct {
    char *type;
    int i_val;
    float f_val;
    char *s_val;
} ExprVal;

#endif /* COMPILER_COMMON_H */