#ifndef FORM
# define FORM
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
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

	void	BeSigned(const Bureaucrat& employee);

	Form();
	Form(std::string name, int tosigned, int toexec);
	~Form();

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

std::ostream& operator<<(std::ostream& out, const Form& paperwork);

#endif