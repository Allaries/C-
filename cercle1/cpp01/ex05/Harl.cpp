#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}


void    Harl::debug(void)
{
    std::cout << " love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!\n";
}

void    Harl::warning(void)
{
    std::cout << "think I deserve to have some extra bacon for free. Ive been coming for years, whereas you started working here just last month\n";
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager NOW !\n";
}

void    Harl::complain(std::string level)
{
    void	(Harl::*funcPtr)(void) = NULL;
    void	(Harl::*funcArray[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string funclevel[4] = {"debug", "info", "warning", "error"};
    int i = -1;
    while (++i < 4)
    {
        if (funclevel[i] == level)
            funcPtr = funcArray[i];
    }
    if (funcPtr == NULL) {
        std::cout << "Harl doesn't complain about this, he is a civilised person !" << std::endl;
        return ;
    }
    (this->*funcPtr)();

}