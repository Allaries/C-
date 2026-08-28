#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"


RobotomyForm::RobotomyForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), target(target)
{
}

RobotomyForm::RobotomyForm(const RobotomyForm &other) : AForm(other)
{
    this->target = other.target;
}

RobotomyForm::~RobotomyForm()
{
}
