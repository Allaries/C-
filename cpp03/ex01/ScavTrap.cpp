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
    std::cout << "[ScavTrap] " << this->name << " is now in gate keeper mode !" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
	this->HitPoint -= amount;
	std::cout << "[ScavTrap] " << this->name << " took " << amount << " damage, outch !" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->Energy <= 0 || this->HitPoint <= 0)
	{
		std::cout << this->name << " is kapput :<" << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << "[ScavTrap] " << this->name << " attacked " << target << " causing him to take " << this->Attack << " point of damage !!" << std::endl;
}


void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->Energy <= 0 || this->HitPoint <= 0)
	{
		std::cout << "[ScavTrap] " << this->name << " is kapput :<" << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << "[ScavTrap] " << this->name << " healed himself " << amount << " he is now at " << this->HitPoint << " HP !" << std::endl;
}