
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
    ~dog();
    void    makeSound();
};

#endif