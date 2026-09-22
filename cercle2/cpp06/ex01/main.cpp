#include "include/Data.hpp"
#include "include/Serializer.hpp"
#include <iostream>

int main(void)
{
    Data      d;
    d.id   = 42;
    d.name = "quarante-deux";

    uintptr_t raw = Serializer::serialize(&d);
    Data*     ptr = Serializer::deserialize(raw);

    std::cout << "original : " << &d  << std::endl;
    std::cout << "raw      : " << raw << std::endl;
    std::cout << "restored : " << ptr << std::endl;
    std::cout << "equal    : " << (ptr == &d ? "yes" : "no") << std::endl;

    // prouve que les données sont intactes à travers l'aller-retour
    std::cout << ptr->id << " " << ptr->name << std::endl;
    return 0;
}