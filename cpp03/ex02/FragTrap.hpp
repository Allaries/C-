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
    ~FragTrap();
    void    highFiveGuys();
};
