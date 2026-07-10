#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default construcor called" << std::endl;
    this->HitPoint = 100;
    this->Energy = 50;
    this->Attack = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap name construcor called" << std::endl;
    this->HitPoint = 100;
    this->Energy = 50;
    this->Attack = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << this->name << " is now in gate keeper mode !" << std::endl;
}