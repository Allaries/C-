#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default construcor called" << std::endl;
    this->HitPoint = 100;
    this->Energy = 50;
    this->Attack = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap name construcor called" << std::endl;
    this->HitPoint = 100;
    this->Energy = 100;
    this->Attack = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void    FragTrap::highFiveGuys()
{
    std::cout << this->name << " is now ready to high five" << std::endl;
}