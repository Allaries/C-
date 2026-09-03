#ifndef PARDON
# define PARDON
# include <iostream>
# include "AForm.hpp"

class PardonForm : virtual public AForm
{
private :
	std::string target;
public:
	PardonForm(std::string target);
	PardonForm(const PardonForm& other);
	void	execute(Bureaucrat const & executor) const;
	~PardonForm();
};


#endif