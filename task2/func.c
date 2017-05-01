#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "func.h"

matrix* create_matrix_from_file(FILE* file)
{
	int rows, cols, notnull;
	if (fscanf(file, "%d %d %d", &rows, &cols, &notnull) != 3)
	{
		printf("error1 \n");
		return NULL;
	}
	if (notnull > (rows * cols))
	{
		printf("notnull elements > amount of elements \n");
		return NULL;
	}	
	matrix* m1 = (matrix*)malloc(sizeof(matrix));
	if (!m1)
	{
		printf("can't allocate %zu bytes", sizeof(double*) * rows);
		return NULL;
	}
	m1->row = rows;
	m1->col = cols;
	m1->not_null = notnull;
	m1->data = (double**)calloc(rows, sizeof(double*));
	if (!m1->data)
	{
		printf("can't allocate %zu bytes", sizeof(double*) * rows);
		return NULL;
	}
	for (int i = 0; i < rows; i++)
	{
		m1->data[i] = (double*)calloc(cols,sizeof(double));
		if (!m1->data[i])
		{
			printf("can't allocate %zu bytes", sizeof(double) * cols);
			return NULL;
		}
	}
	return m1;
}

double get_elem(matrix *m, int row, int col)
{
	return m->data[row][col];
}

void set_elem(matrix *m, int row, int col, double elem)
{
	m->data[row][col] = elem;
}

int real_amount_notnull_elem(FILE *f, matrix* m)
{
	int count = 0; 
	fseek(f, 3*sizeof(int), SEEK_SET);
	while(fgetc(f) != EOF)
	{
		if(fgetc(f) == '\n')
			count++;
	}
	count++;
	if (m->not_null != count)
	{
		printf("amount of notnull elements %d not equal %d\n", count, m->not_null);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int set_notnull_elem(FILE* f, matrix* m)
{
	 int ind_i, ind_j, count = 0;
	 int notnull_elem = m->not_null;
	 double  value;
	 for (int i = 0; i < notnull_elem; ++i)
	 {
	 	if(fscanf(f, "%d %d %lf", &ind_i, &ind_j, &value) != 3)
		{
			printf("error2 \n");
		        return EXIT_FAILURE;
		}
		if((ind_i >= m->row) || (ind_j >= m->col))
		{
			printf("indexs of element > amount of elements \n");
		        return EXIT_FAILURE;
		}
	        set_elem(m, ind_i, ind_j, value);
		count++;
	 }
	if (count !=notnull_elem)
	{
		printf("amount of notnull elements %d not equal %d", count, notnull_elem);	
	} 
	return EXIT_SUCCESS;
}

void print(matrix* m)
{
	int row_n = m->row;
	int col_n = m->col;

	for (int i = 0; i < row_n; i++)
        {
		for (int j = 0; j < col_n; j++)
		{
			printf("%lf ", get_elem(m, i, j));
		}
		printf("\n");
        }
}

int norma_L(matrix* m)
{
	int temp, norm_l = 0;
	int row_n = m->row;
	int col_n = m->col;

	for (int j = 0; j < col_n; j++)
	{
		temp = 0;
		for (int i = 0; i < row_n; i++)
		{
			temp += fabs(get_elem(m, i, j));
		}
		if (temp > norm_l)
		{
			norm_l = temp;
		}
	}
	return norm_l;
}

void free_memory(matrix *m)
{
	for (int i = 0; i < m->row; i++)
	{
		free(m->data[i]);
	}	
	free(m->data);
	free(m);
	m = 0;
}


