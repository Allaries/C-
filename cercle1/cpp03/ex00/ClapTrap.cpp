#include "ClapTrap.hpp"

void    ClapTrap::takeDamage(unsigned int amount)
{
	this->HitPoint -= amount;
	std::cout << "[ClapTrap] " << this->name << " took " << amount << " damage, outch !" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->Energy <= 0 || this->HitPoint <= 0)
	{
		std::cout << this->name << " is kapput :<" << std::endl;
		return ;
	}
	this->Energy--;
	std::cout << "[ClapTrap] "  << this->name << " attacked " << target << " causing him to take " << this->Attack << " point of damage !!" << std::endl;
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy <= 0 || this->HitPoint <= 0)
	{
		std::cout << this->name << " is kapput :<" << std::endl;
		return ;
	}
	this->Energy--;
	this->HitPoint += amount;
	std::cout << "[ClapTrap] "  << this->name << " healed himself " << amount << " he is now at " << this->HitPoint << " HP !" << std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name), HitPoint(10), Energy(10), Attack(0)
{
	std::cout << "[Claptrap] constructor called" << std::endl;
}

ClapTrap::ClapTrap():name("ClapTrap"), HitPoint(10), Energy(10), Attack(0)
{
	std::cout << "[Claptrap] default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
    std::cout << "[Claptrap] Copy constructor called\n";
    *this = other;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "[Claptrap] Copy assignment operator called\n";
    if (this != &other)
    {
        this->name = other.name;
        this->HitPoint = other.HitPoint;
        this->Energy = other.Energy;
        this->Attack = other.Attack;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[Claptrap] destructor called" << std::endl;
}
