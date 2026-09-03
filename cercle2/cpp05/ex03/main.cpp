#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/Intern.hpp"


int main(void)
{
    // std::cout << "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      lllv o /douUP\n         |v///\n          ||||\n         |||\n         ||||\n   .....//||||.....\n";
    try
    {
        Intern clanker;
        AForm *Form1A = clanker.makeForm("", "Kirk");
        Bureaucrat bob("Thierry", 4);
        std::cout << bob << std::endl;
        std::cout << Form1A << std::endl;
        bob.signForm(*Form1A);
        Form1A->execute(bob);
        delete Form1A;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}