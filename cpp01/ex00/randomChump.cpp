#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie cadaver;
    cadaver.setname(name);
    cadaver.announce();
}