#include "Fixed.hpp"

Fixed::Fixed( void )
{
	raw_bit = 0;
}

Fixed::Fixed( const int integer )
{
	Fixed::raw_bit = integer << Fixed::point_position_within;
}

Fixed::Fixed( const float floating_point )
{
	Fixed::raw_bit = roundf(floating_point * (1 << Fixed::point_position_within));
}

Fixed::Fixed(const Fixed &rhd )
{
	*this = rhd;
}



float Fixed::toFloat( void ) const
{
	return (float)((float)Fixed::raw_bit) / (1 << Fixed::point_position_within);
}

 int Fixed::toInt( void ) const
{
	return (int)Fixed::raw_bit >> Fixed::point_position_within;
}



int Fixed::getRawBits( void ) const
{
	return Fixed::raw_bit;
}

void Fixed::setRawBits( int const raw )
{
	Fixed::raw_bit = raw;
}




Fixed &Fixed::min( Fixed &A, Fixed &B )
{
	if (A.getRawBits() < B.getRawBits())
		return (A);
	return (B);
}

Fixed const &Fixed::min(Fixed const &A, Fixed const &B )
{
	if (A.getRawBits() < B.getRawBits())
		return (A);
	return (B);
}

Fixed &Fixed::max( Fixed &A, Fixed &B )
{
	if (A.getRawBits() < B.getRawBits())
		return (B);
	return (A);
}

Fixed const &Fixed::max(Fixed const &A, Fixed const &B )
{
	if (A.getRawBits() < B.getRawBits())
		return (B);
	return (A);
}



bool Fixed::operator>(Fixed const &rhd) const
{
	return (this->getRawBits() > rhd.getRawBits());
}

bool Fixed::operator<(Fixed const &rhd) const
{
	return (this->getRawBits() < rhd.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhd) const
{
	return (this->getRawBits() >= rhd.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhd) const
{
	return (this->getRawBits() <= rhd.getRawBits());
}

bool Fixed::operator==(Fixed const &rhd) const
{
	return (this->getRawBits() == rhd.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhd) const
{
	return (this->getRawBits() != rhd.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &rhd)
{
	raw_bit = rhd.raw_bit;
	return *this;
}

Fixed Fixed::operator+(Fixed const &rhd)
{
	Fixed tmp_instance(*this);

	tmp_instance.setRawBits(Fixed::raw_bit + rhd.getRawBits());
	return (tmp_instance);
}

Fixed Fixed::operator-(Fixed const &rhd)
{
	Fixed tmp_instance(*this);

	tmp_instance.setRawBits(Fixed::raw_bit - rhd.getRawBits());
	return (tmp_instance);
}

Fixed Fixed::operator*(Fixed const &rhd)
{
	Fixed tmp_instance(*this);
	long long multiply_value;

	multiply_value = (long long)Fixed::raw_bit * (long long)rhd.getRawBits();
	tmp_instance.setRawBits((int)(multiply_value / (1 << Fixed::point_position_within)));
	return tmp_instance;
}

Fixed Fixed::operator/(Fixed const &rhd)
{
	Fixed tmp_instance(*this);
	float division_value;

	division_value = (float)Fixed::raw_bit / (float)rhd.getRawBits();
	tmp_instance.setRawBits(roundf(division_value * (1 << Fixed::point_position_within)));
	return (tmp_instance);
}

Fixed &Fixed::operator++()
{
	Fixed::raw_bit++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp (*this);
	Fixed::raw_bit++;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	Fixed::raw_bit--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp (*this);
	Fixed::raw_bit--;
	return (tmp);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}



Fixed::~Fixed( void )
{
}
