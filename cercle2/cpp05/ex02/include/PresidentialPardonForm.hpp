#ifndef PARDON
# define PARDON
# include <iostream>
# include "AForm.hpp"

class PardonForm : virtual public AForm
{
public:
	PardonForm();
	PardonForm(const PardonForm& other);
	void	execute(Bureaucrat const & executor) const;
	~PardonForm();
};


#endif