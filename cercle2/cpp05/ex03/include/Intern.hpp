#ifndef INTERN
# define INTERN
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    ~Intern();
    AForm static *PardonFormC (std::string target);
    AForm static *RobotomyFormC (std::string target);
    AForm static *ShrubberyFormC (std::string target);
    AForm*  makeForm(std::string type, std::string target);
};

#endif