#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "[Constructors] WrongCat" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &rhd)
{
	std::cout << "[Copy Constructors] WrongCat" << std::endl;
    *this = rhd;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "옹냐~ 옹냐~" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhd)
{
    this->type = rhd.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[destructors] WrongCat" << std::endl;
}
