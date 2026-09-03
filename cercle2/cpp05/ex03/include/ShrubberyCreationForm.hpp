#ifndef SHRUBBERY
# define SHRUBBERY
# include <iostream>
#include <fstream>
# include "AForm.hpp"

class ShrubberyForm : virtual public AForm
{
private :
	std::string target;
public:
	ShrubberyForm(std::string target);
	ShrubberyForm(const ShrubberyForm& other);
	void	execute(Bureaucrat const & executor) const;
	~ShrubberyForm();
};


#endif