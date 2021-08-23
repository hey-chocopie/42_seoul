#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	raw_bit = 0;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhd )
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::raw_bit = rhd.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhd)
{
	std::cout << "Assignation operator called" << std::endl;
	raw_bit = rhd.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return Fixed::raw_bit;
}

void Fixed::setRawBits( int const raw )
{
	Fixed::raw_bit = raw;
}

