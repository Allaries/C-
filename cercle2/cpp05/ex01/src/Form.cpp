#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

int     Form::getsign(void) const
{
    return (this->tosign);
}

int     Form::getexec(void) const
{
    return (this->toexec);
}

std::string     Form::getname(void) const
{
    return (this->name);
}

void    Form::BeSigned(const Bureaucrat& employee)
{
    if (this->issigned == 1)
    {
        std::cout << employee.getName() << " couldn't sign " << this->name << " because it was already signed" << std::endl;
        return ;
    }
    if (employee.getGrade() <= this->tosign)
    {
        std::cout << employee.getName() << " signed " << this->name << std::endl;
        this->issigned = 1;
    }
    else
    {
        std::cout << employee.getName() << " couldn't sign " << this->name << " because his grade too low" << std::endl;
        throw GradeTooLowException();
    }
}

Form::Form():name("random form"), issigned(0), tosign(150), toexec(75)
{
}

Form::Form(std::string name, int tosigned, int toexec):name(name),tosign(tosigned), toexec(toexec)
{
    if (tosigned < 1)
		throw GradeTooHighException();
	if (tosigned > 150)
		throw GradeTooLowException();
    if (toexec < 1)
		throw GradeTooHighException();
	if (toexec > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Form& paperwork)
{
	out << paperwork.getname() << " Need grade " << paperwork.getsign() << " to be signed and grade " << paperwork.getexec() << " to be executed";
	return out;
}