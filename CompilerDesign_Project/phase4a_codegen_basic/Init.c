#include "global.h"

struct entry keywords[] = {
	"div", DIV,
	"mod", MOD,
	"if", IF,
	"then", THEN,
	"while", WHILE,
	"do", DO,
	"begin", BEGIN,
	"end", END,
	0,0
};

void init(void)
{
	struct entry* p;
	for (p = keywords; p->token; p++)
		insert(p->lexptr, p->token);
}