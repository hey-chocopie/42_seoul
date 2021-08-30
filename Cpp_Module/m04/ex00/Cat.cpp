#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Constructors] Cat" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &rhd)
{
	std::cout << "[Copy Constructors] Cat" << std::endl;
    *this = rhd;
}

void	Cat::makeSound( void ) const
{
	std::cout << "냐옹~ 냐옹~" << std::endl;
}

Cat &Cat::operator=(const Cat &rhd)
{
    this->type = rhd.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "[destructors] Cat" << std::endl;
}
