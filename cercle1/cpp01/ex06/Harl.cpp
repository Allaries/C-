#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}


void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
    this->info();
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!\n";
    this->warning();
}

void    Harl::warning(void)
{
    std::cout << "think I deserve to have some extra bacon for free. Ive been coming for years, whereas you started working here just last month\n";
    this->error();
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager NOW !\n";
}

void    Harl::complain(std::string level)
{
    std::string funclevel[4] = {"debug", "info", "warning", "error"};
    int i = -1;
    while (++i < 4)
    {
        if (funclevel[i] == level)
            break;
    }
    switch (i)
    {
    case 0:
        this->debug();
        break;
    case 1:
        this->info();
        break;
    case 2:
        this->warning();
        break;
    case 3:
        this->error();
        break;
    default:
        std::cout << "Harl doesn't complain about this, he is a civilised person !" << std::endl;
        break;
    }
}