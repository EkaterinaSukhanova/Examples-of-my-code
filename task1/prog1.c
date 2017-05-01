/* Вывод первых n строк файла или последних n строк файла в зависимости от переданных параметров. Например, ./prog filename last 10 или ./prog filename first 10. Аналог head/tail
1. строки разделяются \n
2. имя файла передается как первый аргумент программе
3. исключительно как доп.информация для развития в каждой задаче описан аналогичный существующий инструмент для решения этой задачи - готовая программа. */



#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "func.h"

int main(int argc, char *argv[])
{	
	const char *prog_name=argv[0];
	if (argc !=4)
	{ 
		printf("usage: %s num\n", prog_name);
		return 1;
	}

	FILE *f=fopen(argv[1],"r");
	if(f==0)
	{
		printf("not found %s\n",argv[1]);
		return 1;
	}

	const char *h_t=argv[2];
	if(strcmp(h_t,"first")!=0 && strcmp(h_t,"last")!=0)
	{
		printf("wrog %s\n",argv[2]);
		return 1;
	}

	const int n=atoi(argv[3]);
	const int len=file_len(f);
	if(n>len)
	{
		printf("over big numder %s\n",argv[3]);
		return 1;
	}

	fclose(f);

	f=fopen(argv[1],"r");
	
	//если ввели first
	if(strcmp(h_t,"first")==0)
	{
		argv2_first(n,f);
	}

	//если ввели last
	if(strcmp(h_t,"last")==0)
	{
		argv2_last(len,n,f);
	}

	fclose(f);
	return 0;
}
