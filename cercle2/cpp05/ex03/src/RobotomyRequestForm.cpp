#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"

void	RobotomyForm::execute(Bureaucrat const & executor) const
{
    std::srand(std::time(NULL));
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
    if (std::rand() % 2 == 0)
        std::cout << "The subject " << this->target << " , has been robotomized successfully" << std::endl;
    else
        std::cout << " * sdfbwefshkfkfbkwebfwbfhwejhfwjefj * Where " << this->target << " last words" << std::endl;
    
}

RobotomyForm::RobotomyForm(std::string target) : AForm("Robotomy Request Form", 72, 45), target(target)
{
}

RobotomyForm::RobotomyForm(const RobotomyForm &other) : AForm(other)
{
    this->target = other.target;
}

RobotomyForm::~RobotomyForm()
{
}
