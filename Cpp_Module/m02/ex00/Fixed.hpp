#ifndef __FIXED_H__
#define __FIXED_H__
#include <iostream>

class Fixed{
	private:
		int raw_bit;
		static const int point_position_within = 8;

	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed &rhd );
		Fixed &operator=(const Fixed &rhd);

		int getRawBits( void ) const; 
		void setRawBits( int const raw );
};

#endif
