#include "HumanB.hpp"

void	HumanB::attack(void)
{
	std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *nWeapon)
{
	this->weapon = nWeapon;
}

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}
