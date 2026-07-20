#include "../include/WrongCat.hpp"

void	Wcat::makeSound()
{
	std::cout << "*MIAOUUUUUUUUUUU*" << std::endl;
	return ;
}

Wcat::Wcat() : Wanimal()
{
    std::cout << "Mewgenic disaster incoming" << std::endl;
    this->setType("Wcat");
}

Wcat::~Wcat()
{
    std::cout << "This cat was too ugly for this world" << std::endl;
}