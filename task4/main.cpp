/* Разработать классы для описанных ниже объектов. Включить в класс конструкторы, 
конструктор  копирования, деструктор,  методы  set(...), get(...),  show(...). 
Память  под  строковые  поля  необходимо  выделять динамически. 
Определить другие необходимые методы.

Book: Автор, Название, Издательство, Год, Количество страниц.
Создать массив объектов. Вывести:
а) список книг заданного 
автора;
б) список книг, выпущенных заданным издательством;
в) список книг, выпущенных после заданного года. */

#include <iostream>
#include <cstring>
#include <fstream>
#include "Book.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	const char *prog_name = argv[0];
	if (argc != 2)
	{
		cout << "error1\n";
		return 0;
	}

	ifstream fin(argv[1]);

	if(!fin.is_open())
	{
		cout << "File not found\n";
		return 0;
	}

	Book* library = new Book[50];
	int i = 0;
	while(!fin.eof())
	{
		char name[50];
		char author[50];
		char publish_office[50];
		int year;
		int amount_of_pages;

		fin >> name;
		if(fin.eof())
		{
			break;
		}
		fin >> author;
		fin >> publish_office;
		fin >> year;
		fin >> amount_of_pages;

		library[i].set_all(name, author, publish_office, year, amount_of_pages);
		i++;
	}
	int amount_books = i;
  fin.close();

	int var;
	cout << "1. вывести список книг заданного автора," << std::endl;
	cout << "2. список книг, выпущенных заданным издательством,\n";
	cout << "3. список книг, выпущенных после заданного года\n";
	cin >> var;
	if(menu(library, amount_books, var) == -1)
	{
		delete[] library;
		return 0;
	}
	delete[] library;
	return 0;
}
