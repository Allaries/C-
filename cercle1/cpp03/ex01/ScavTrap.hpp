#include "ClapTrap.hpp"

class ScavTrap : protected ClapTrap
{
private:
    void foo(){
        name = "Scavy";
    }
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ScavTrap& operator=(ScavTrap const &other);
    ~ScavTrap();
    void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
    void    guardGate();
};
