#include "../include/animal.hpp"

void    animal::getType()
{
	std::cout << "this animal is a " << this->type << std::endl;
}

void	animal::setType(std::string type)
{
	this->type = type;
}

void	animal::makeSound()
{
	std::cout << "*Weird noises*" << std::endl;
	return ;
}

//Constructeur / destructeur //

animal::animal()
{
	std::cout << "default animal constructor called" << std::endl;
	this->setType("weird looking camel");
}

animal::animal(const animal &copy)
{
	std::cout << "copy animal constructor called" << std::endl;
	*this = copy;
}

animal::~animal()
{
	std::cout << "animal destructor called" << std::endl;
}