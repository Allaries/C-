#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    void foo(){
        name = "Scavy";
    }
public:
    ScavTrap();
    ScavTrap(std::string name);
    ~ScavTrap();
    void    guardGate();
};
