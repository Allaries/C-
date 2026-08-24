#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a(0);
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(10.0f);

	std::cout << "a is " << a.ToInt() << " as integer" << std::endl;
	std::cout << "b is " << b.ToInt() << " as integer" << std::endl;
	std::cout << "c is " << c.ToInt() << " as integer" << std::endl;
	std::cout << "d is " << d.ToInt() << " as integer" << std::endl;

	std::cout << "is b < c ? " << (b<c) << std::endl;
	std::cout << "is b == d ? " << (b==d) << std::endl;
	std::cout << "is b > d ? " << (b>d) << std::endl;
	std::cout << "is c <= d ? " << (c<=d) << std::endl;
	std::cout << "a + b = " << (c+b) << std::endl;
	std::cout << "d - c = " << (c-d) << std::endl;
	std::cout << "c * d = " << (c*d) << std::endl;
	std::cout << "c / d = " << (c/b) << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	return 0;
}
