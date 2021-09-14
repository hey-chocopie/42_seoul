#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__
#include <iostream>
#include <string>

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &rhd);
		virtual ~Animal();

		std::string		getType() const;

		virtual Animal &operator=(const Animal &rhd);
};

#endif
