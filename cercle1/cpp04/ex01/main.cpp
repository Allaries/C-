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

    dog* boii = new dog(*dynamic_cast<dog*>(doggo));
    boii->getType();
    boii->makeSound();
    boii->readMind();
    delete boii;
    delete doggo;

    std::cout << std::endl << std::endl;

    animal* kitty = new cat();
    kitty->getType();
    kitty->makeSound();
    delete kitty;

    std::cout << std::endl << std::endl;

    Wanimal* pinguin = new Wanimal();
    pinguin->getType();
    pinguin->makeSound();
    delete pinguin;

    std::cout << std::endl << std::endl;

    Wanimal* camel = new Wcat();
    camel->getType();
    camel->makeSound();
    delete camel;

    std::cout << std::endl;
}