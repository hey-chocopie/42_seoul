# C++ - Module 02
Ad-hoc polymorphism, operators overload and
orthodox canonical classes

# Exercise 00: My First Orthodox
> 한줄평 : 부동소수점과 고정소수점 개념을 공부했고, 복사 연산자와 =operator을 사용해 보았다. 

```
Exercise 00: My First Orthodox Class
Turn-in directory : ex00/
Files to turn in : Makefile, main.cpp, Fixed.hpp and Fixed.cpp
Forbidden functions : None
```

You know integers and you also know floating point numbers. How cute.
Please read this 3-page article (1, 2, 3) to discover that you don’t. Go on, read it.
Until today, any numbers you used in your programs were basically integers or floating
point numbers, or any of their variants (short, char, long, double, etc). From your previous reading, it’s safe to assume that integers and floating point numbers have opposite
caracteristics.
But today, this will change. You are going to discover a new and awesome number
type: fixed point numbers! Always missing from most languages scalar types, fixed point
numbers offer a valuable balance between performance, accuracy, range and precision that
explains why these numbers are widely used in graphics, sound or scientific programming
to name a few.
As C++ lacks fixed point numbers, you’re going to add them yourself today. I’d recommend this article from Berkeley as a start. If it’s good for them, it’s good for you. If
you have no idea what Berkeley is, read this section of their wikipedia page.

Write an orthodox class to represent fixed point numbers:
• Private members:
◦ An integer to store the fixed point value.
◦ A static constant integer to store the number of fractional bits. This constant will always be the litteral 8.
• Public members:
◦ A default constructor that initializes the fixed point value to 0.
◦ A destructor.
◦ A copy constructor.
◦ An assignation operator overload.
◦ A member function int getRawBits( void ) const; that returns the raw
value of the fixed point value.
◦ A member function void setRawBits( int const raw ); that sets the raw
value of the fixed point value.
The code:

```
#include <iostream>
int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
```
메인문의 위, 

```
$> ./a.out
Default constructor called
Copy constructor called
Assignation operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
```
 > Should output something like:


# Exercise 01: Towards a more useful
```
 Exercise 01: Towards a more useful fixed point class
Turn-in directory : ex01/
Files to turn in : Makefile, main.cpp, Fixed.hpp and Fixed.cpp
Allowed functions : roundf (from <cmath>)
```

Ok, ex00 was a good start, but our class is still pretty useless, being only able to
represent the fixed point value 0.0. Add the following public constructors and public
member functions to your class:
• A constructor that takes a constant integer as a parameter and that converts it to
the correspondant fixed(8) point value. The fractional bits value is initialized like
in ex00.
• A constructor that takes a constant floating point as a parameter and that converts
it to the correspondant fixed(8) point value. The fractional bits value is initialized
like in ex00.
• A member function float toFloat( void ) const; that converts the fixed point
value to a floating point value.
• A member function int toInt( void ) const; that converts the fixed point value
to an integer value.
You will also add the following function overload to your header (declaration) and
source (definition) files:
• An overload to the « operator that inserts a floating point representation of the
fixed point value into the parameter output stream.
The code:
Should output something like:

```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
```


```
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Assignation operator called
Float constructor called
Assignation operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

# Exercise 02: Now we’re talking
> 한줄평 : operator 연산자를 사용해 보았고, 고정소수점 비교연산자와 산술연산자 모두 사용해 보았다. 고정 소수점을 곱하거나 나눌경우 << 8을 raw_bit에 해준 상태이기 떄문에, raw_bit끼리 곱하거나 나눈후 추가적인 처리를 해주어야한다! 
다른 operator들은 비슷했지만, "<<"을 사용할때는 ostream을 사용해야해서 operator<< 은 전역변수로 선언하고 사용했다. 


```
Turn-in directory : ex02/
Files to turn in : Makefile, main.cpp, Fixed.hpp and Fixed.cpp
Allowed functions : roundf (from <cmath>)
```

We’re getting closer. Add the following public member operator overloads to your
class:
• Six comparison operators: >, <, >=, <=, == and !=.
• Four arithmetic operators: +, -, *, and /.
• The pre-increment, post-increment, pre-decrement and post-decrement operators,
that will increment or decrement the fixed point value from the smallest representable  such as 1 +  > 1.
Add the following public static member functions overloads to your class:
• The static member function min that takes references on two fixed point values and
returns a reference to the smallest value, and an overload that takes references on
two constant fixed point values and returns a reference to the smallest constant
value.
• The static member function max that takes references on two fixed point values
and returns a reference to the biggest value, and an overload that takes references
on two constant fixed point values and returns a reference to the biggest constant
value.

It’s up to you to test every feature of your class, but the short code:

```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
```

Should output something like (I deleted the ctors/dtor logs):
```
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```
