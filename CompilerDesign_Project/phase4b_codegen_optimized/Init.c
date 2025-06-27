#include "global.h"

struct entry keywords[] = {
	"div", DIV,
	"mod", MOD,
	"if", IF,
	"while", WHILE,
	"do", DO,
	"begin", BEGIN,
	"end", END,
	"then", THEN,
	"main", MAIN,  
	"function", FUNCTION, 
	"repeat", REPEAT,
	"until", UNTIL,
	0,0
};

void init()
{
	struct entry* p;
	for (p = keywords; p->token; p++)
		insert(p->lexptr, p->token);
}