#ifndef CATCLASS
# define CATCLASS
# include "animal.hpp"

class cat : public animal
{
private:
    std::string type;
public:
    cat();
    ~cat();
    void    makeSound();
};

#endif