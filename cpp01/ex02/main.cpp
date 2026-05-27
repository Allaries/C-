#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "\nstring :\n";
	std::cout << &str;
	std::cout << "\nstringPTR :\n";
	std::cout << &stringPTR;
	std::cout << "\nstringREF :\n";
	std::cout << &stringREF;

	std::cout << "\nstring :\n";
	std::cout << str;
	std::cout << "\nstringPTR :\n";
	std::cout << stringPTR;
	std::cout << "\nstringREF :\n";
	std::cout << stringREF;
	std::cout << "\n";
}