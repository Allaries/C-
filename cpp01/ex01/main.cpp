#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    std::cout << "zombieHorde :\n";
    Zombie *Horde = zombieHorde(5,"Danielz");
    int i = -1;
    while (++i < 5)
        Horde[i].announce();
    delete[] Horde;
}