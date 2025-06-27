#include "global.h"

FILE* input, * output, * err;

int main()
{

	output = fopen("file3.obj", "w");
	err = fopen("file.err", "w");
	input = fopen("file.exp", "r");

	init();
	parse();

	exit(0);

	return 0;
}
