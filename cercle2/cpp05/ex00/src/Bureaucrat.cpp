#include "../include/Bureaucrat.hpp"

const std::string	Bureaucrat::getName(void)
{
	return (this->name);
}

int Bureaucrat::getGrade(void)
{
	return (this->grade);
}

Bureaucrat::Bureaucrat():name("Soulless Bureaucrat"), grade(150){
}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name)
{
	if (grade < 1 || grade > 150)
		throw GradeTooLowException;
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}