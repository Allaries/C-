
#ifndef DOGCLASS
# define DOGCLASS
# include "animal.hpp"

class dog : virtual public animal
{
private:
    std::string type;
public:
    dog();
    ~dog();
    void    makeSound();
};

#endif