#include "global.h"

int lookahead;
int label_count = 0;

void parse()
{
	lookahead = lexan();
	while (lookahead != DONE) {
		stmt(); match(';');
	}
}

void expr()
{
	int t;
	term();

	while (1)
		switch (lookahead) {
		case '+': case '-':
			t = lookahead;
			match(lookahead);
			term();
			emit(t, NONE);
			continue;
		default:
			return;
		}
}

void term()
{
	int t;
	factor();
	while (1)
		switch (lookahead) {
		case '*': case '/': case DIV: case MOD:
			t = lookahead;
			match(lookahead); factor(); emit(t, NONE);
			continue;
		default:
			return;
		}
}

void factor()
{
	switch (lookahead) {
	case '(':
		match('('); expr(); match(')'); break;
	case NUM:
		emit(NUM, tokenval);
		match(NUM); break;
	case ID:
		emit(ID, tokenval);
		match(ID);
		break;
	default:
		error("syntax error");
	}
}

int ifOrwhile;

void match(int t)
{
	if (lookahead == t)
		lookahead = lexan();
	else error("syntax error");
}

void CS();

void stmt() {
	int tok = tokenval;
	switch (lookahead) {
	case ID:
		match(ID);
		match('=');
		expr();
		fprintf(output, "pop %s\n", symtable[tok].lexptr);
		break;
	case IF:
		match(IF);
		match('(');
		logExpr(0); 
		match(')');
		fprintf(output, "pop r2\ncomp r2, 0\nbe else\n");
		match(THEN);
		stmt();
		fprintf(output, "else\n");
		break;
	case WHILE:
		match(WHILE);
		fprintf(output, "while\n");
		match('(');
		logExpr(1); 
		match(')');
		fprintf(output, "pop r2\ncomp r2,0\nbe end while\n");
		match(DO);
		stmt();
		fprintf(output, "b while\nend while\n");
		break;

	case BEGIN:
		match(BEGIN);
		fprintf(output, "; begin block\n");
		CS();
		match(END);
		break;
	default:error("Syntax error\n");

	}
}


void logExpr(int ifOrwhile) {
	expr();
	logRest(ifOrwhile);
}

void logRest(int ifOrwhile) {
	switch (lookahead) {
	case '<':
		match('<');
		expr();
		log1(ifOrwhile);
		break;
	case '>':
		match('>');
		expr();
		log2(ifOrwhile);
		break;
	case '!':
		match('!');
		expr();
		log3(ifOrwhile);
		break;

	default:
		log4(ifOrwhile);
		break;
	}
}

void CS() {
	while (lookahead != END) {
		stmt();
		match(';');
	}
}

void log1(int ifOrwhile) {
	if (ifOrwhile == 0)
		fprintf(output, "pop r2\npop r1\ncmp r2, r1\nble else\n");
	else if(ifOrwhile ==1)
		fprintf(output, "pop r2\npop r1\ncmp r2, r1\nble end while\n"); //less
}

void log2(int ifOrwhile) {
	if (ifOrwhile ==0)
		fprintf(output, "pop r2\npop r1\ncmp r2, r1\nbge else\n");
	else if (ifOrwhile == 1)
		fprintf(output, "pop r2\npop r1\ncmp r2, r1\nbge end while\n"); // greater
}
void log3(int ifOrwhile) {
	if (ifOrwhile == 0)
		fprintf(output, "pop r2\npop r1\ncmp r2, r1\nbe else\n");
	else if (ifOrwhile == 1)
		fprintf(output, "pop r2\npop r1\ncmp r2, r1\nbe end while\n"); //equal
}
void log4(int ifOrwhile) {
	if (ifOrwhile == 0)
		fprintf(output, "pop r2\ncmp r2, r0\nbe else\n");
	else if (ifOrwhile == 1)
		fprintf(output, "pop r2\ncmp r1, 0\nbe end while\n");
}