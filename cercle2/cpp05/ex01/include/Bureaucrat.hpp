#ifndef BUREAUCRAT
# define BUREAUCRAT
# include <iostream>
# include <exception>
# include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	
	public:
		//functions
		void	signForm(Form paperwork);
		//getter
		const std::string getName();
		int getGrade();
		
		//grade things
		void	IncrementGrade();
		void	DecrementGrade();
		
		// exceptions
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
		
		//constructor
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
};

#endif