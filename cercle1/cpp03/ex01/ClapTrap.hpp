#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	int HitPoint;
	int Energy;
	int Attack;
public:
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &other);
	ClapTrap& operator=(ClapTrap const &other);
	~ClapTrap();
};
