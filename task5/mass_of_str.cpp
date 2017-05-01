#include <iostream>
#include <cstring>
#include <fstream>
#define max_str_size 1000
#include "mass_of_str.hpp"
using namespace std;

mass_of_str::mass_of_str(size_t size, istream &file):size(size)
{
	str = new char*[size];
	for(int i = 0; i < size; ++i)
	{
		char* buffer = new char[max_str_size];
		file.getline(buffer, max_str_size);
		str[i] = new char[strlen(buffer) + 1];
		memcpy(str[i], buffer, (strlen(buffer) + 1) * sizeof(char));
		delete[] buffer;
	}
}

mass_of_str::~mass_of_str()
{
	for(int i = 0; i < size; ++i)
	{
		delete[] str[i];
		str[i] = 0;
	}
	delete[] str;
	str = 0;
}

mass_of_str::mass_of_str(mass_of_str &mass2)
{
	size = mass2.size;
	str = new char*[size];
	for(int i = 0; i < size; ++i)
	{
		str[i] = new char[strlen(mass2.str[i]) + 1];
		strcpy(str[i], mass2.str[i]);
	}
}

void mass_of_str::print()
{
	for(int i = 0; i < size; ++i)
	{
		cout << str[i];
		cout << endl;
	}
}

void mass_of_str::print_number_str(int i)
{
	cout << str[i];
}

//упорядонние строк в лексикографическом порядке
void mass_of_str::sort()
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = i+1; j < (size); ++j)
		{
			if(strcmp(str[i], str[j]) > 0)
			{
				char* tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
}

//конкатенация двух массивов
void mass_of_str::concatenation(mass_of_str &mass2)
{
	size_t new_text_size = 0;
	if(size >= mass2.size)
	{
		new_text_size = size;
	}
	else
	{
		new_text_size = mass2.size;
	}

	char** new_text = new char*[new_text_size];

	for(int i = 0; i < new_text_size; ++i)
	{
		if(i < size && i < mass2.size)
		{
			new_text[i] = new char[strlen(str[i]) + strlen(mass2.str[i]) + 1];
			strcpy(new_text[i], str[i]);
			strcat(new_text[i], mass2.str[i]);
		}
		else if ( i < size && i >= mass2.size)
		{
			new_text[i] = new char[strlen(str[i]) + 1];
			strcpy(new_text[i], str[i]);
		}
		else if (i >= size && i < mass2.size)
		{
			new_text[i] = new char[strlen(mass2.str[i]) + 1];
			strcpy(new_text[i], mass2.str[i]);
		}
		else if (i >= size && i >= mass2.size)
		{
			break;
		}
	}

	for(int i = 0; i < size; ++i)
	{
		delete[] str[i];
	}
	delete[] str;

	str = new_text;
	size = new_text_size;
}

//слияние двух массивов с удалением повторяющихся строк
void mass_of_str::merger_and_finding_repeat(mass_of_str &mass2)
{
	size_t new_text_size = size + mass2.size;
	char** new_text = new char*[new_text_size];
	int i = 0;
	for(i; i < size; ++i)
	{
		new_text[i] = new char[strlen(str[i]) + 1];
		strcpy(new_text[i], str[i]);
	}

	int g = 0;
	int j = i;
	for(j, g; j < new_text_size && g < mass2.size; ++j, g++)
	{
		new_text[j] = new char[strlen(mass2.str[g]) + 1];
		strcpy(new_text[j], mass2.str[g]);
	}

	bool* flag = new bool[new_text_size];
	for(int i = 0; i < new_text_size; ++i)
	{
		flag[i] = true;
	}
	size_t real_size_of_mass = new_text_size;
	for(int y = 0; y < new_text_size; ++y)
	{
		for(int z = y + 1; z < new_text_size; ++z)
		{
			if(flag[z] && strcmp(new_text[y], new_text[z]) == 0)
			{
				flag[z] = false;
				real_size_of_mass--;
			}
		}
	}

	char** mass_without_repeats = new char*[real_size_of_mass];

	int z = 0;
	for(int y = 0; y < new_text_size && z < real_size_of_mass; ++y)
	{
		if(flag[y])
		{
			mass_without_repeats[z] = new char[strlen(new_text[y])+1];
			strcpy(mass_without_repeats[z], new_text[y]);
			++z;
		}
	}

	for(int i = 0; i < size; ++i)
	{
		if(str[i] != NULL)
		{
			delete[] str[i];
		}
	}
	delete[] str;

	for(int i = 0; i < new_text_size; ++i)
	{
		if(new_text[i] != NULL)
		{
			delete[] new_text[i];
		}
	}
	delete[] new_text;
	delete[] flag;

	str = mass_without_repeats;
	size = real_size_of_mass;
}

//функция по заданию
void merger_sort_print(mass_of_str &mass1, mass_of_str &mass2)
{
	mass1.merger_and_finding_repeat(mass2);
	mass1.sort();
	mass1.print();
}

int counting_number_of_str(istream &file)
{
	char* buffer = new char[max_str_size];
	int number_of_str = 0;
	while(!file.eof())
	{
		file.getline(buffer, max_str_size);
		number_of_str++;
	}
	file.clear();
	file.seekg(0, file.beg);

	delete[] buffer;
	return number_of_str;
}
