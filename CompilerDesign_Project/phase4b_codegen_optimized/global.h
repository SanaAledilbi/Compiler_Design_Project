#ifndef GLOBAL_H
#define GLOBAL_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BSIZE 128
#define NONE -1
#define EOS '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260
#define IF 261
#define THEN 262
#define END 263
#define WHILE 264
#define DO 265
#define BEGIN 266
#define MAIN 267 //new
#define FUNCTION 268  //new
#define REPEAT 269
#define UNTIL 270

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
void start();
void dec();
void Fundec();
void Mainfun();
void rest();
void func1();
void func2();
void func3();
void main1();
void main2();

#endif
