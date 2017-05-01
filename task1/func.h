#include <stdio.h> 
#ifndef FUNC_H
#define FUNC_H

void print_first(int to, char **m);
void print_last(int from, int num, char **m);
int file_len(FILE *file);
void argv2_first(int n,FILE *f);
void argv2_last(int len, int n,FILE *f);


#endif
