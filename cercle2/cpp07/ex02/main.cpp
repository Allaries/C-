#include "Array.hpp"


int	main(void){
	try
	{
		Array<int> A(10);
		std::cout << A[123] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}