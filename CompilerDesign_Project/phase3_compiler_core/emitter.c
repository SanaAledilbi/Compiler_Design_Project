#include "global.h"

void emit(int t, int tval)
{
	switch (t) {
	case '+':
		fprintf(output, "pop r1\npop r2\nadd r2, r1\npush r2\n");
		break;
	case '-':
		fprintf(output, "pop r1\npop r2\nsub r2, r1\npush r2\n");
		break;
	case '*':
		fprintf(output, "pop r1\npop r2\nmul r2, r1\npush r2\n");
		break;
	case '/':
		fprintf(output, "pop r1\npop r2\ndiv r2, r1\npush r2\n");
		break;
	case DIV:
		fprintf(output, "pop r1\npop r2\nDIV r2, r1\npush r2\n");
		break;
	case MOD:
		fprintf(output, "pop r1\npop r2\nMOD r2, r1\npush r2\n");
		break;
	case NUM:
		fprintf(output, "push %d\n", tval);
		break;
	case ID:
		fprintf(output, "push %s\n", symtable[tval].lexptr);
		break;
	default:
		fprintf(output, "token %d, tokenval %d\n", t, tval);
	}
}

