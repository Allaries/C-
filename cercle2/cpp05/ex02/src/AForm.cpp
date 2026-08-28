#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

int     AForm::getsign(void) const
{
    return (this->tosign);
}

int     AForm::getexec(void) const
{
    return (this->toexec);
}

std::string     AForm::getname(void) const
{
    return (this->name);
}

bool    AForm::executable(void) const
{
    return (this->issigned);
}

void    AForm::BeSigned(const Bureaucrat& employee)
{
    if (this->issigned == 1)
    {
        std::cout << employee.getName() << " couldn't sign " << this->name << " because ";
        throw AlreadySignedException();
    }
    if (employee.getGrade() <= this->tosign)
    {
        std::cout << employee.getName() << " signed " << this->name << std::endl;
        this->issigned = 1;
    }
    else
    {
        std::cout << employee.getName() << " couldn't sign " << this->name << " because ";
        throw GradeTooLowException();
    }
}

void	AForm::execute(Bureaucrat const & executor) const
{
    std::cout << executor.getName() << " : bro i'm not signing this" << std::endl;
}

AForm::AForm():name("random form"), issigned(0), tosign(150), toexec(148)
{
}

AForm::AForm(std::string name, int tosigned, int toexec):name(name), issigned(0),tosign(tosigned), toexec(toexec)
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

AForm::AForm(const AForm &other): name(getname()), issigned(0), tosign(other.getsign()), toexec(other.getexec())
{
}

AForm::~AForm()
{
}

const char* AForm::NotSignedException::what() const throw()
{
	return "This form is not signed";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "Already Signed";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& paperwork)
{
	out << paperwork.getname() << " Need grade " << paperwork.getsign() << " to be signed and grade " << paperwork.getexec() << " to be executed";
	return out;
}