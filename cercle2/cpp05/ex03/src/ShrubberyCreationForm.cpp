#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void	ShrubberyForm::execute(Bureaucrat const & executor) const
{
    if (this->executable() == 0)
    {
        std::cout << executor.getName() << " couldn't execute " << this->getname() << " because ";
        throw NotSignedException();
    }
    if (executor.getGrade() > this->getexec())
    {
        std::cout << executor.getName() << " couldn't execute " << this->getname() << " because ";
        throw GradeTooLowException();
    }
    std::string filename = this->target;
    filename.append("_shrubbery");
    std::ofstream outflux(filename.c_str());
    if (outflux)
        outflux << "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      lllv o /douUP\n         |v///\n          ||||\n         |||\n         ||||\n   .....//||||.....\n" << std::endl;
    else
    {
        std::cout << "error when creating " << this->target << "_shrubbery, try again later" << std::endl;
        return ;
    }
    std::cout << executor.getName() << " executed " << this->getname() << std::endl;
}

ShrubberyForm::ShrubberyForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
}

ShrubberyForm::ShrubberyForm(const ShrubberyForm &other) : AForm(other)
{
    this->target = other.target;
}

ShrubberyForm::~ShrubberyForm()
{
}
