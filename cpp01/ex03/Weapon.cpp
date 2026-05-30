#include "Weapon.hpp"

void	Weapon::setType(std::string str)
{
	this->type = str;
}

const std::string	&Weapon::getType() const
{
	return (this->type);
}

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{
}
