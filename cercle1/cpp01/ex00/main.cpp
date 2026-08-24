#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    std::cout << "randomChump :\n";
    randomChump("Miguel");
    std::cout << "newZombie :\n";
    Zombie* a = newZombie("Daniel");
    a->announce();
    delete a;
}