#include <iostream>
#include <cstring>
#include "Book.hpp"

using namespace std;

Book::Book()
{
	name = NULL;
	author = NULL;
	publish_office = NULL;
	year = 0;
	amount_of_pages = 0;
}

Book::~Book()
{
	delete[] author;
	delete[] name;
	delete[] publish_office;
	name = NULL;
	author = NULL;
	publish_office = NULL;
}

char* Book::get_author()
{
	return author;
}
char* Book::get_name()
{
	return name;
}
char* Book::get_publish_office()
{
	return publish_office;
}
int Book::get_year()
{
	return year;
}
int Book::get_amount_of_pages()
{
	return amount_of_pages;
}

void Book::set_all(char* name, char* author, char* publish_office, int year, int amount_of_pages)
{
	if(name)
	{
		size_t len = strlen(name)+1;
		this->name = new char[len];
		memcpy(this->name, name, len);
	}
	if(author)
	{
		size_t len = strlen(author)+1;
		this->author = new char[len];
		memcpy(this->author, author, len);
	}
	if(publish_office)
	{
		size_t len = strlen(publish_office)+1;
		this->publish_office = new char[len];
		memcpy(this->publish_office, publish_office, len);
	}
	if(year)
	{
		this->year = year;
	}
	if(amount_of_pages)
	{
		this->amount_of_pages = amount_of_pages;
	}
}

void Book::show_author()
{
	int i = 0;
	while(author[i] != '\0')
	{
		cout << author[i];
		++i;
	}
	cout << '\n';
}
void Book::show_name()
{
	int i = 0;
	while(name[i] != '\0')
	{
		cout << name[i];
		++i;
	}
	cout << '\n';
}
void Book::show_publish_office()
{
	int i = 0;
	while(publish_office[i] != '\0')
	{
		cout << publish_office[i];
		++i;
	}
	cout << '\n';
}
void Book::show_year()
{
	cout << year << '\n';
}
void Book::show_amount_of_pages()
{
	cout << amount_of_pages << '\n';
}

void need_author_or_publish_office(char* need_author_or_publish_office, Book* library, int amount_books)
{
	for(int i = 0; i < amount_books; i++)
		{
			if(((strcmp(library[i].get_author(), need_author_or_publish_office)) == 0) ||
			 ((strcmp(library[i].get_publish_office(), need_author_or_publish_office)) == 0))
			{
				library[i].show_name();
			}
		}
}
void need_after_year(int year, Book* library, int amount_books)
{
	for(int i = 0; i < amount_books; i++)
	{
		if(library[i].get_year() > year)
		{
			library[i].show_name();
		}
	}
}

int menu(Book* library, int amount_books, int var)
{
	if(var == 1)
	{
		char need_author[50];
		cout << "author: ";
		cin >> need_author;
		need_author_or_publish_office(need_author, library, amount_books);
	}
	else if(var == 2)
	{
		char need_publ_office[50];
		cout << "publish_office: ";
		cin >> need_publ_office;
		need_author_or_publish_office(need_publ_office, library, amount_books);
	}
	else if(var == 3)
	{
		int need_year;
		cout << "year: ";
		cin >> need_year;
		need_after_year(need_year, library, amount_books);
	}
	else
	{
		cout << "error3\n";
		return -1;
	}
}
