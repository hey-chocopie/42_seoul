#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__
#include "WrongAnimal.hpp"

class WrongCat :public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat &rhd);
		~WrongCat();


		void makeSound( void ) const;

		WrongCat &operator=(const WrongCat &rhd);
};

#endif
