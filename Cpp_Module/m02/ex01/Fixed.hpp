#ifndef __FIXED_H__
#define __FIXED_H__
#include <iostream>
#include <ostream>

class Fixed{
	private:
		int raw_bit;
		static const int point_position_within = 8;

	public:
		Fixed( void );
		Fixed( const int integer );
		Fixed( const float floating_point );
		~Fixed( void );
		Fixed( const Fixed &rhd );
		Fixed &operator=(const Fixed &rhd);
		int getRawBits( void ) const; 
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
};


std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
