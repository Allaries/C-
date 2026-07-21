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
    std::cout << "[FragTrap] " << this->name << " is now ready to high five" << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount)
{
	this->HitPoint -= amount;
	std::cout << "[FragTrap] " << this->name << " took " << amount << " damage, outch !" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->Energy <= 0 || this->HitPoint <= 0)
	{
		std::cout << "[FragTrap] " << this->name << " is kapput :<" << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << "[FragTrap] " << this->name << " attacked " << target << " causing him to take " << this->Attack << " point of damage !!" << std::endl;
}


void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->Energy <= 0 || this->HitPoint <= 0)
	{
		std::cout << this->name << " is kapput :<" << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << "[FragTrap] " << this->name << " healed himself " << amount << " he is now at " << this->HitPoint << " HP !" << std::endl;
}