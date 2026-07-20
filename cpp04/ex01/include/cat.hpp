#ifndef CATCLASS
# define CATCLASS
# include "animal.hpp"
# include "brain.hpp"

class cat : public animal
{
private:
    std::string type;
    brain *caboche;
public:
    cat();
    ~cat();
    void    makeSound();
};

#endif