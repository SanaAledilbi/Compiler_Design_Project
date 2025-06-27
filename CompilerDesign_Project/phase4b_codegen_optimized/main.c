#include "global.h"

FILE* input, * output, * err;

int main()
{

	output = fopen("file4b.obj", "w");
	err = fopen("file.err", "w");
	input = fopen("file.exp", "r");

	/*if (input == NULL) {
		printf("file doesn't exist ");
	}*/

	init();
	parse();

	exit(0);

	return 0;
}
