#include "Fixed.hpp"
#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	//default test case
	std::cout << "default test case" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	//test case : >, <, >=, <=, == and !=.
	std::cout << "\ntest case : >, <, >=, <=, == and !=" << std::endl;
	Fixed d(9);
	std::cout << "d = " << d << " b = " << b << std::endl;
	std::cout << "d > b == " << (d > b) << std::endl;
	std::cout << "d < b == " << (d < b) << std::endl;
	std::cout << "d >= b == " << (d >= b) << std::endl;
	std::cout << "d <= b == " << (d <= b) << std::endl;
	std::cout << "d == b == " << (d == b) << std::endl;
	std::cout << "d != b == " << (d != b) << std::endl;

	//test case : / * + -
	std::cout << "\ntest case : + - * /" << std::endl;
	Fixed c(100);
	std::cout << "c = " << c << " b = " << b << std::endl;
	std::cout << "c + b == " << (c + b) << std::endl;
	std::cout << "c - b == " << (c - b) << std::endl;
	std::cout << "c * b == " << (c * b) << std::endl;
	std::cout << "c / b == " << (c / b) << std::endl;
	std::cout << "c = " << c << " b = " << b << std::endl;

	//test case : min, max
	std::cout << "\ntest case : min, max" << std::endl;
	Fixed test_a(3);
	Fixed const test_b(3);
	std::cout << "a = " << a << " b = " << b << "  test = " << test_a << std::endl;
	std::cout << "max a, test = " << Fixed::max( a, test_a ) << std::endl;
	std::cout << "max b, test = " << Fixed::max( b, test_b ) << std::endl;
	std::cout << "min a, test = " << Fixed::min( a, test_a ) << std::endl;
	std::cout << "min b, test = " << Fixed::min( b, test_b ) << std::endl;


	return 0;
}
