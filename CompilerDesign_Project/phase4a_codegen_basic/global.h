#ifndef GLOBAL_H
#define GLOBAL_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NONE -1
#define EOF '\0'
#define BSIZE 128
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260
#define IF 261
#define THEN 262
#define WHILE 263
#define DO 264
#define BEGIN 265
#define END 266


extern FILE* input, * output, * err;

extern int lookahead;
extern int lineno;
extern int tokenval;
extern int label_count;

struct entry {
	char* lexptr;
	int token;
};

extern struct entry symtable[];

int lexan();
void emit(int t, int tval);
void error(char* m);
int lookup(char s[]);
int insert(char s[], int tok);
void parse();
void expr();
void term();
void factor();
void match(int t);
void init(void);
void CS();
void stmt();
void logExpr(int ifOrwhile);
void logRest(int ifOrwhile);
void log1(int ifOrwhile);
void log2(int ifOrwhile);
void log3(int ifOrwhile);
void log4(int ifOrwhile);
#endif
