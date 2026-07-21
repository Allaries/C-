#include <iostream>

class ClapTrap
{
private:
	std::string name;
	int HitPoint;
	int Energy;
	int Attack;
public:
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	ClapTrap(std::string name);
	ClapTrap();
	ClapTrap(ClapTrap const &other);
	ClapTrap& operator=(ClapTrap const &other);
	~ClapTrap();
};
