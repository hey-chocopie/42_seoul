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
		static std::string kind_list[5]; //static을 쓴이유는, 생성되는 인스턴스 들이, kind_list를 공유하며 사용할려고. static은 프로그램이 실행될 때 만 실행되므로, 인스턴스 새로 만들어도 기존에 만들어둔 kind_list는 그대로 있음. , static은 전역변수로 초기화한다.
		int ADD(int *index);
		int search_print(int *index);
		void print_book_value();
		void clean_data();
};

#endif
