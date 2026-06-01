#include "Harl.hpp"

int main(void)
{
    Harl Harl;
    std::string level;
    std::cout << "In what mood Harl is in now ?\n";
    std::cin >> level;
    Harl.complain(level);
}