#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"

void	PardonForm::execute(Bureaucrat const & executor) const
{
    std::cout << executor.getName() << " : PARDON LA FRANCE J'AI CHIE DANS MON BEN" << std::endl;
}

PardonForm::PardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
}

PardonForm::PardonForm(const PardonForm &other) : AForm(other)
{

}

PardonForm::~PardonForm()
{
}