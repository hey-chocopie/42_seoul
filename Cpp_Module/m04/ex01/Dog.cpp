#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
	this->A = new Brain();
	std::cout << "[Constructors] Dog" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &rhd)
{
	this->A = new Brain();
	std::cout << "[Copy Constructors] Dog" << std::endl;
    *this = rhd;
}

void	Dog::makeSound(void) const
{
	std::cout << "머엉 머엉 으를르르릉" << std::endl;
}


Brain	*Dog::getBrain(void)
{
	return (this->A);
}

void	Dog::setideas(int index, std::string ideas)
{
	if(index >= 0 && index <= 99)
		A->setideas(index, ideas);
}

std::string *Dog::getideas(void)
{
	return (A->getideas());
}

Dog &Dog::operator=(const Dog &rhd)
{
    this->type = rhd.type;
	*A = *(rhd.A);
	// deep copy 주소 안넣고 그냥 값넣어서 복사
	return (*this);
}

Dog::~Dog()
{
	delete this->A;
	std::cout << "[destructors] Dog" << std::endl;
}

