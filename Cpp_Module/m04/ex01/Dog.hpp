#ifndef __DOG_HPP__
#define __DOG_HPP__
#include "Brain.hpp"

class Dog :public Animal{
	private:
		Brain *A;
	public:
		Dog();
		Dog(const Dog &rhd);
		~Dog();

		void makeSound( void ) const;
		Brain		*getBrain(void);
		void		setideas(int index, std::string ideas);
		std::string *getideas(void);
		Dog &operator=(const Dog &rhd);
};

#endif

