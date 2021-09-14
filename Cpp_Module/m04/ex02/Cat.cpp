#include "Cat.hpp"

Cat::Cat()
{
	this->A = new Brain();
	std::cout << "[Constructors] Cat" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &rhd)
{
	this->A = new Brain();
	std::cout << "[Copy Constructors] Cat" << std::endl;
    *this = rhd;
}

void	Cat::makeSound( void ) const
{
	std::cout << "냐옹~ 냐옹~" << std::endl;
}

Brain	*Cat::getBrain(void)
{
	return (this->A);
}

Cat &Cat::operator=(const Cat &rhd)
{
    this->type = rhd.type;
	*A = *(rhd.A);
	return *this;
}

Cat::~Cat()
{
	delete this->A;
	std::cout << "[destructors] Cat" << std::endl;
}
