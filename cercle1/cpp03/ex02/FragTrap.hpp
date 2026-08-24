#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    void foo(){
        name = "Scavy";
    }
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    FragTrap& operator=(FragTrap const &other);
    ~FragTrap();
	void	takeDamage(unsigned int amount);
    void	attack(const std::string& target);
	void	beRepaired(unsigned int amount);
    void    highFiveGuys();
};
