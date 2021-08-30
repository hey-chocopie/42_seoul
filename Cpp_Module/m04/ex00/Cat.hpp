#ifndef __Cat_HPP__
#define __Cat_HPP__
#include "Animal.hpp"

class Cat :public Animal{
	public:
		Cat();
		Cat(const Cat &rhd);
		~Cat();

		
		void makeSound( void ) const;

		Cat &operator=(const Cat &rhd);
};

#endif
