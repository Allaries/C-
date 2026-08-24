#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class phonebook
{
private:
	Contact contact[8];
	bool	is_full;
	int		index;
public:
	phonebook();
	~phonebook();
	void	NEW(void);
	void	SEARCH(void);
};

#endif
