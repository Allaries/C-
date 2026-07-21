#ifndef BRAINCLASS
# define BRAINCLASS
# include <iostream>

class brain
{
private:
    std::string ideas[100];
public:
    brain();
    ~brain();
    void    firstIdea();
};




#endif