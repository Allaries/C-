#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
	std::string str = argv[1];
	std::cout << str[0] << std::endl;
	if (argc != 2)
	{
		std::cout << "you need one and only one argument that must be a char, int , float or double" << std::endl;
		return (0);
	}
	if (str.length() == 1)
	{
		if (argv[1][0] < 48 ||  argv[1][0] > 57)
			std::cout << "char : " << argv[1][0] << std::endl << "int : " << (int) argv[1][0] << std::endl;
	}
	std::cout << "char : " << (char) atoi(argv[1]) << std::endl << "int : " <<  atoi(argv[1]) << std::endl;
}