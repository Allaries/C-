#include "../include/Bureaucrat.hpp"

const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::DecrementGrade(void)
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::IncrementGrade(void)
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::signForm(AForm &paperwork)
{
	paperwork.BeSigned(*this);
}

Bureaucrat::Bureaucrat():name("Soulless Bureaucrat"), grade(150){
}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	this->grade = other.grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	if (&other == this)
		return ;
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& employee)
{
	out << employee.getName() << " bureaucrat grade " << employee.getGrade();
	return out;
}