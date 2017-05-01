#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>

typedef struct Matrix
{
	double** data;
	int row;
	int col;
	int not_null;
}matrix;

matrix* create_matrix_from_file(FILE* f1);
double get_elem(matrix *m, int row, int col);
void set_elem(matrix *m, int row, int col, double elem);
int real_amount_notnull_elem(FILE *f, matrix *m);	
int set_notnull_elem(FILE* f, matrix* m);
void print(matrix* m);
int norma_L(matrix* m);
void free_memory(matrix *m);

#endif
