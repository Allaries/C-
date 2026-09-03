#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"

void	PardonForm::execute(Bureaucrat const & executor) const
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
    std::cout << executor.getName() << " executed " << this->getname() << std::endl;
    std::cout << "With all the power I possess, I, Lord Zaphod Beeblebrox, pardon you " << this->target << " , and wish you a great day" << std::endl;
}

PardonForm::PardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), target(target)
{
}

PardonForm::PardonForm(const PardonForm &other) : AForm(other)
{
    this->target = other.target;
}

PardonForm::~PardonForm()
{
}
