#ifndef __FIXED_H__
#define __FIXED_H__
#include <iostream>
#include <ostream>
#include <cmath>
class Fixed{
	private:
		int raw_bit;
		static const int point_position_within = 8;

	public:
		Fixed( void );
		Fixed( const int integer );
		Fixed( const float floating_point );
		Fixed( const Fixed &rhd );

		int getRawBits( void ) const; 
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed &min(Fixed &A, Fixed &B);
		static Fixed const &min(Fixed const &A, Fixed const &B);
		static Fixed &max(Fixed &A, Fixed &B);
		static Fixed const &max(Fixed const &A, Fixed const &B);

		Fixed &operator=(const Fixed &rhd);

		bool operator>(Fixed const &rhd) const;
		bool operator<(Fixed const &rhd) const;
		bool operator>=(Fixed const &rhd) const;
		bool operator<=(Fixed const &rhd) const;
		bool operator==(Fixed const &rhd) const;
		bool operator!=(Fixed const &rhd) const;

		Fixed operator+(Fixed const &rhd);
		Fixed operator-(Fixed const &rhd);
		Fixed operator*(Fixed const &rhd);
		Fixed operator/(Fixed const &rhd);

		Fixed &operator++( void ); // Prefix increment operator
		Fixed operator++( int ); // Postfix increment operator.
		Fixed &operator--( void );
		Fixed operator--(int);

		~Fixed( void );
};


std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
