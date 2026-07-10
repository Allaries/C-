#include "ClapTrap.hpp"

void    ClapTrap::takeDamage(unsigned int amount)
{
	this->HitPoint -= amount;
	std::cout << this->name << " took " << amount << " damage, outch !" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->Energy <= 0 || this->HitPoint <= 0)
	{
		std::cout << this->name << " is kapput :<" << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << this->name << " attacked " << target << " causing him to take " << this->Attack << " point of damage !!" << std::endl;
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy <= 0 || this->HitPoint <= 0)
	{
		std::cout << this->name << " is kapput :<" << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << this->name << " healed himself " << amount << " he is now at " << this->HitPoint << " HP !" << std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name), HitPoint(10), Energy(10), Attack(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap():name("ClapTrap"), HitPoint(10), Energy(10), Attack(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
