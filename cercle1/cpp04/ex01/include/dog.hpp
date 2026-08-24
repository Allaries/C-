
#ifndef DOGCLASS
# define DOGCLASS
# include "animal.hpp"
# include "brain.hpp"

class dog : virtual public animal
{
private:
    std::string type;
    brain *caboche;
public:
    dog();
    dog(const dog& other);
    ~dog();
    void    readMind();
    void    makeSound();
};

#endif