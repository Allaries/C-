#include <iostream>
#include "Point.hpp"

int main( void ) 
{
	Point A(0,0);
	Point B(0,5);
	Point C(5,0);
	Point P(2.6f ,2.5f);

	std::cout << bsp(A, B, C, P) << std::endl;
	return 0;
}
