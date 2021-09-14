#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Construct] Brain" << std::endl;
}

Brain::Brain(Brain &rhd)
{
	*this = rhd;
}

std::string *Brain::getideas( void )
{
	return (ideas);
}

void		Brain::setideas( int index, std::string ideas )
{
	this->ideas[index] = ideas;
}

Brain &Brain::operator=(Brain &rhd)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = rhd.ideas[i];
	}
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "[destructed] Brain" << std::endl;
}

