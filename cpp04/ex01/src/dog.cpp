#include "../include/dog.hpp"

void	dog::makeSound()
{
	std::cout << "*Barking loudly*" << std::endl;
    return ;
}

void    dog::readMind()
{
    this->caboche->firstIdea();
}

dog::dog() : animal()
{
    std::cout << "A good boy appeared" << std::endl;
    this->setType("Dog");
    this->caboche = new brain();
}

dog::dog(const dog& other) : animal(other)
{
    *this = other;
    this->caboche = new brain(*other.caboche);
    std::cout << "dog cloned" << std::endl;
}

dog::~dog()
{
    std::cout << "The good boy vanished from thin air" << std::endl;
    delete this->caboche;
}