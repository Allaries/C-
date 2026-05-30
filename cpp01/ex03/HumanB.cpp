#include "HumanB.hpp"

void	HumanB::attack(void)
{
	std::cout << this->name << " attack with their " << this->weapon.getType() << std::endl;
}

HumanB::HumanB()
{
}

HumanB::~HumanB()
{
}
