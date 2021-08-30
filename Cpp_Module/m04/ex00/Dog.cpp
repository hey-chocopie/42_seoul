#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Constructors] Dog" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &rhd)
{
	std::cout << "[Copy Constructors] Dog" << std::endl;
    *this = rhd;
}

void	Dog::makeSound(void) const
{
	std::cout << "머엉 머엉 으를르르릉" << std::endl;
}

Dog &Dog::operator=(const Dog &rhd)
{
    this->type = rhd.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[destructors] Dog" << std::endl;
}

