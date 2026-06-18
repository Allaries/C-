#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed const d ( b );

	std::cout << "a is " << a << " as float" << std::endl;
	std::cout << "b is " << b << " as float" << std::endl;
	std::cout << "c is " << c << " as float" << std::endl;
	std::cout << "d is " << d << " as float" << std::endl;

	std::cout << "a is " << a.ToInt() << " as integer" << std::endl;
	std::cout << "b is " << b.ToInt() << " as integer" << std::endl;
	std::cout << "c is " << c.ToInt() << " as integer" << std::endl;
	std::cout << "d is " << d.ToInt() << " as integer" << std::endl;
	return 0;
}