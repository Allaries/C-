#ifndef WCATCLASS
# define WCATCLASS
# include "WrongAnimal.hpp"

class Wcat : public Wanimal
{
private:
    std::string type;
public:
    Wcat();
    ~Wcat();
    void    makeSound();
};

#endif