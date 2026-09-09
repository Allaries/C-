#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/Intern.hpp"


int main(void)
{
    try
    {
        Intern clanker;
        AForm *Form1A = clanker.makeForm("Shrubbery", "Kirk");
        if (!Form1A)
            return (0);
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