#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__
#include <iostream>
#include <string>

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &rhd);
		virtual ~WrongAnimal();

		std::string		getType() const;
		void			makeSound(void) const;

		WrongAnimal &operator=(const WrongAnimal &rhd);
};

#endif
