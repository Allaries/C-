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
    const std::string getName();
    int getGrade();
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat();
    class GradeTooLowException : public std::exception
    530
};

#endif