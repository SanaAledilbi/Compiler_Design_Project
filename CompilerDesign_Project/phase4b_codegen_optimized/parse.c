#include "global.h"

int tok;
int lookahead;
//int label_count = 0;

void parse() {
	lookahead = lexan();
	//while (lookahead != DONE) {
	//	stmt(); match(';');

	start();
	//match(DONE);

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

void match(int t)
{
	if (lookahead == t)
		lookahead = lexan();
	else error("syntax error");
}

void CS();

// modified
void stmt() {

	switch (lookahead) {
	case ID:
		tok = tokenval;
		match(ID);
		rest(); //new
		//match('=');
		//expr();
		//fprintf(output, "pop %s", symtable[tok].lexptr);
		break;
	case IF:
		match(IF);
		match('(');
		expr();
		match(')');
		fprintf(output, "pop r2\ncomp r2, 0\nbe else\n");
		match(THEN);
		stmt();
		fprintf(output, "else:\n");
		break;
	case WHILE:
		fprintf(output, "while:\n");
		match(WHILE);
		match('(');
		expr();
		match(')');
		fprintf(output, "pop r2\ncomp r2,0\nbe end while\n");
		match(DO);
		stmt();
		fprintf(output, "b while\nend while\n");
		break;

	case BEGIN:
		match(BEGIN);
		CS();
		match(END);
		break;
	default:error("Syntax error\n");

	}
}

// modified
void CS() {
	
		while (lookahead != END) {
			stmt();
			match(';');
		}
	
}

// new functions below
void start() {
	dec();
	Mainfun();
	match(DONE);
}

void dec() {
	while (lookahead == FUNCTION){
		Fundec();
		match(';');
	}
}

void Fundec() {
	match(FUNCTION);
	fprintf(output, "%s:\n", symtable[tokenval].lexptr); //func1();
	match(ID);
	match('(');
	match(')');
	match(BEGIN);
	CS();
	match(END);
	fprintf(output, "ret\n"); //func2();
}

void Mainfun() {
	match(MAIN);
	fprintf(output, "main:\n"); //main1();
	match('(');
	match(')');
	match(BEGIN);
	CS();
	match(END);
	fprintf(output, "exit\n"); //main2();
}

void rest() {

	switch (lookahead){
	case '=':
		match('=');
		expr();
		fprintf(output, "pop %s\n", symtable[tok].lexptr);
		break;
	case '(':
		match('(');
		match(')');
		fprintf(output, "call %s:\n", symtable[tok].lexptr); //func3();
		break;
	default:
		return;
	}
}

void func1()
{
	fprintf(output, "%s:\n", symtable[tokenval].lexptr);
}

void func2()
{
	fprintf(output, "ret\n");
}

void func3()
{
	fprintf(output, "call %s:\n", symtable[tokenval].lexptr);
}

void main1()
{
	fprintf(output, "main:\n");
}
void main2()
{
	fprintf(output, "exit\n");
}
