#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact
{
private:
	std::string	info[5];

public:
				Contact(void);
				~Contact();
	void		new_contact(void);
	void		print_tab(void);
	void		print_info(void);
};

#endif