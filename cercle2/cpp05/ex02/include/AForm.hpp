#ifndef FORM
# define FORM
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				issigned;
	const int			tosign;
	const int			toexec;

public:

	int			getsign() const;
	int			getexec() const;
	std::string	getname() const;

	virtual void	execute(Bureaucrat const & executor) const = 0;
	void	BeSigned(const Bureaucrat& employee);

	AForm();
	AForm(const AForm &other);
	AForm(std::string name, int tosigned, int toexec);
	
	virtual ~AForm();

	class AlreadySignedException : public std::exception
	{
		public :
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
    {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& paperwork);

#endif