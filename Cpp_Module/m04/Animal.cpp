#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Constructors] Animal" << std::endl;
	type = "";
}


Animal::Animal(std::string type)
{
	std::cout << "[Constructors] Animal" << std::endl;
	this->type = type;
}


Animal::Animal(const Animal &rhd)
{
	std::cout << "[Copy Constructors] Animal" << std::endl;
	*this = rhd;
}


std::string		Animal::getType() const
{
	return (this->type);
}

void			Animal::makeSound(void) const
{
	std::cout << "Animal makesound" << std::endl;
}


Animal &Animal::operator=(const Animal &rhd)
{
	this->type = rhd.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[destructors] Animal" << std::endl;
}
