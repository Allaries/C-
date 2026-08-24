#ifndef BUREAUCRAT
# define BUREAUCRAT
# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:

	//constructor
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	
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
};

#endif