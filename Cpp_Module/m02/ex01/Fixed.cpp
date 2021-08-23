#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	raw_bit = 0;
}

Fixed::Fixed( const int integer )
{
	std::cout << "Int constructor called" << std::endl;
	Fixed::raw_bit = integer << Fixed::point_position_within;
}

Fixed::Fixed( const float floating_point )
{
	std::cout << "Float constructor called" << std::endl;
	Fixed::raw_bit = roundf(floating_point * (1 << Fixed::point_position_within));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhd )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhd;
	//Fixed::raw_bit = rhd.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhd)
{
	std::cout << "Assignation operator called" << std::endl;
	raw_bit = rhd.raw_bit;
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

float Fixed::toFloat( void ) const
{
	return (float)((float)Fixed::raw_bit) / (1 << Fixed::point_position_within);
}

 int Fixed::toInt( void ) const
{
	return (int)Fixed::raw_bit >> Fixed::point_position_within;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
