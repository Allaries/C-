#ifndef ANIMALCLASS
# define ANIMALCLASS
# include <iostream>

class animal
{
protected:
    std::string type;
public:
    animal();
    animal(const animal &copy);
    virtual ~animal();
    virtual void    makeSound();
    void            getType();
    void            setType(std::string type);
};
#endif