#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include <iostream>
# include <iomanip>

int input_data(std::string *str);
class phone_book
{
	private:
		std::string str;
		std::string book_value[5];
	public:
		static std::string kind_list[5];
		int ADD(int *index);
		int search_print(int *index);
		void print_book_value();
		void clean_data();
};

#endif
