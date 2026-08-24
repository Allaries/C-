#ifndef FORM
# define FORM
# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

class Form
{
private:
	const std::string	name;
	bool				issigned;
	const int			tosign;
	const int			toexec;

public:

	void	BeSigned(Bureaucrat employee);

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


#endif