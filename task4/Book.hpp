#ifndef BOOK_HPP
#define BOOK_HPP

class Book
{
	public:
		Book();
		~Book();
		void set_all(char* name, char* author, char* publish_office, int year, int amount_of_pages);
		void set_author(char* author);
		void set_publish_office(char* publish_office);
		void set_year(int year);
		void set_amount_of_pages(int set_amount_of_pages);
		char* get_author();
		char* get_name();
		char* get_publish_office();
		int get_year();
		int get_amount_of_pages();
		void show_author();
		void show_name();
		void show_publish_office();
		void show_year();
		void show_amount_of_pages();

	private:
		char* author;
		char* name;
		char* publish_office;
		int year;
		int amount_of_pages;
};

void need_author_or_publish_office(char* need_author_or_publish_office, Book* library, int amount_books);
void need_after_year(int year, Book* library, int amount_books);
int menu(Book* library, int amount_books, int var);

#endif
