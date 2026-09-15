#include <iostream>
#include <cstdlib>
#include "include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "lack of, or too many argument, only 1 is needed" << std::endl;
		return (0);
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
}