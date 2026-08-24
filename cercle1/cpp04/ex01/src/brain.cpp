#include "../include/brain.hpp"

brain::brain()
{
    this->ideas[0] = "food";
}

brain::~brain()
{
}

void    brain::firstIdea()
{
    std::cout << "thinking about " << this->ideas[0] << std::endl;
}