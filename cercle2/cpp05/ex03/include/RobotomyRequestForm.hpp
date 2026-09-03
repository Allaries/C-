#ifndef ROBOTOMY
# define ROBOTOMY
# include <iostream>
# include "AForm.hpp"
#include <cstdlib>
#include <ctime>


class RobotomyForm : virtual public AForm
{
private :
	std::string target;
public:
	RobotomyForm(std::string target);
	RobotomyForm(const RobotomyForm& other);
	void	execute(Bureaucrat const & executor) const;
	~RobotomyForm();
};


#endif