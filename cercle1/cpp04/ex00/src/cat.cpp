#include "../include/cat.hpp"

void	cat::makeSound()
{
	std::cout << "*Mewing in a silly way*" << std::endl;
	return ;
}

cat::cat() : animal()
{
    std::cout << "LOOK, a cute cat !" << std::endl;
    this->setType("Cat");
}

cat::~cat()
{
    std::cout << "This cat was too cute for this world" << std::endl;
}