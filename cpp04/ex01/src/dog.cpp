#include "../include/dog.hpp"

void	dog::makeSound()
{
	std::cout << "*Barking loudly*" << std::endl;
    return ;
}

dog::dog() : animal()
{
    std::cout << "A good boy appeared" << std::endl;
    this->setType("Dog");
    this->caboche = new brain();
}

dog::~dog()
{
    std::cout << "The good boy vanished from thin air" << std::endl;
    delete this->caboche;
}