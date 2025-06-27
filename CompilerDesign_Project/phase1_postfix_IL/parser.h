#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Global variable
int lookahead;

// Function prototypes (Infix to Prefix)
void expr_infix(void);
void rest_infix(void);
void term(void);
void match(int);
void error(void);

// Function prototypes (Code Optimization)
void expr_optimize(void);
void rest_optimize(void);

#endif // PARSER_H

