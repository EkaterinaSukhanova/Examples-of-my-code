#include <stdlib.h>
#include <stdio.h>


void print_first(const int to, char **m)
{
	for(int j=0;j<to;j++)
		printf("%s\n",m[j]);
}
 
void print_last(const int from,const int num, char **m)
{
	for(int j=(from-1);j>(from-1-num);j--)
		printf("%s\n",m[j]);
}
 
int file_len(FILE *file)
{
	int p=0;
	char *str=(char *)malloc(100*sizeof(char));
	while((fgets(str,100,file))!=NULL)
	{
		p++;
	}	
	free(str);
	return p;
}

//argv[2]=first
void argv2_first(const int n,FILE *f)
{
	char** mass=(char**)malloc(n*sizeof(char*));
	for(int i=0;i<n;i++)
	{
		mass[i]=(char*)malloc(100*sizeof(char));
	}
	
	for(int i=0;i<n;i++)
	{
		fgets(mass[i],100,f);
	}
		
	print_first(n,mass);
		
	for(int i=0;i<n;i++)
		free(mass[i]);
	free(mass);
}

//argv[2]=last
void argv2_last(const int len, const int n,FILE *f)
{
	char** mass=(char**)malloc(len*sizeof(char*));
	for(int i=0;i<len;i++)
	{
		mass[i]=(char*)malloc(100*sizeof(char));
	}
	
	//записываем ввсе строки в массив
	for(int i=0;i<len;i++)
	{
		fgets(mass[i],100,f);
	}

	print_last(len,n,mass);
	
	for(int i=0;i<len;i++)
		free(mass[i]);
	free(mass);
}


