#include "include/animal.hpp"
#include "include/dog.hpp"
#include "include/cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"


int main()
{
    animal* doggo = new dog();
    doggo->getType();
    doggo->makeSound();
    delete doggo;
}