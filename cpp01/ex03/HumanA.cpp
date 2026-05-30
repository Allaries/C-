#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << this->name << " attack with their " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, std::string weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
}
