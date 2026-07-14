#include "../include/WrongAnimal.hpp"

void    Wanimal::getType()
{
	std::cout << "this Wanimal is a " << this->type << std::endl;
}

void	Wanimal::setType(std::string type)
{
	this->type = type;
}

void	Wanimal::makeSound()
{
	std::cout << "*uesdgfdgsfhegfu*" << std::endl;
	return ;
}

//Constructeur / destructeur //

Wanimal::Wanimal()
{
	std::cout << "something strange appeared" << std::endl;
	this->setType("weird looking camel");
}

Wanimal::Wanimal(const Wanimal &copy)
{
	std::cout << "copy Wanimal constructor called" << std::endl;
	*this = copy;
}

Wanimal::~Wanimal()
{
	std::cout << "The anomaly has been purged" << std::endl;
}