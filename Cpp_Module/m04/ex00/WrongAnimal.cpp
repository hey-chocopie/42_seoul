#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[Constructors] WrongAnimal" << std::endl;
	type = "";
}


WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "[Constructors] WrongAnimal" << std::endl;
	this->type = type;
}


WrongAnimal::WrongAnimal(const WrongAnimal &rhd)
{
	std::cout << "[Copy Constructors] WrongAnimal" << std::endl;
	*this = rhd;
}


std::string		WrongAnimal::getType() const
{
	return (this->type);
}

void			WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal makesound" << std::endl;
}


WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhd)
{
	this->type = rhd.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[destructors] WrongAnimal" << std::endl;
}
