#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << this->name;
    std::cout << ": Braiiiiiiinnnzzz\n";
}

void    Zombie::setname(std::string name)
{
    this->name = name;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << this->name;
    std::cout << " is destroyed\n";
}