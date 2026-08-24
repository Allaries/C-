#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << this->name;
    std::cout << ": Braiiiiiiinnnzzz\n";
}

Zombie* newZombie(std::string name)
{
    Zombie* cadaver = new Zombie();
    cadaver->setname(name);
    return (cadaver);
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