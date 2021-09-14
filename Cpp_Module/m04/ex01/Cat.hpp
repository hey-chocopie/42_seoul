#ifndef __Cat_HPP__
#define __Cat_HPP__
#include "Animal.hpp"
#include "Brain.hpp"

class Cat :public Animal{
	private:
		Brain *A;
	public:
		Cat();
		Cat(const Cat &rhd);
		~Cat();

		
		void makeSound( void ) const;
		Brain   *getBrain(void);

		Cat &operator=(const Cat &rhd);
};

#endif
