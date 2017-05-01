//Variant 5

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "func.h"

int main(int argc, char *argv[])
{
	const char *prog_name = argv[0];
	if (argc != 2)
	{
		printf("usage: %s num\n", prog_name);
		return EXIT_FAILURE;
	}

	FILE *file = fopen(argv[1], "r");
	if (file == 0)
	{
		printf("not found %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
//	printf("chisla %d %d %d\n", rows, cols, notnull);
	matrix* m1 = create_matrix_from_file(file);
	if(m1 == NULL)
	{
		return EXIT_FAILURE;
	}

	if(real_amount_notnull_elem(file, m1) == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}

	fseek(file, (5), SEEK_SET);
//   	long pos;
//	pos = ftell(file);
//	printf("pos %ld\n", pos);

	if (set_notnull_elem(file, m1) == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}
	
	fclose(file);

	print(m1);

	int norma = norma_L(m1);

	free_memory(m1);

	printf("norma %d\n", norma);
	return EXIT_SUCCESS;
}
