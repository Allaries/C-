#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* cadaver = new Zombie();
    cadaver->setname(name);
    return (cadaver);
}