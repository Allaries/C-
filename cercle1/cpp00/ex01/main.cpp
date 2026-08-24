#include <iostream>
#include "phonebook.hpp"
#include "contact.hpp"


int main(void)
{
	phonebook PhoneBook;
	std::string str;
	std::cout << "- ADD to create a new contact\n- SEARCH to see all existing contact\n- EXIT to exit (thx captain obvious)\n";
	while (1)
	{
		std::cout << "Type your command : ";
		getline(std::cin >> std::ws, str);
		if (str.compare(0, 5, "EXIT", 0, 5) == 0)
			return (1);
		else if (str.compare(0, 4, "ADD", 0, 4) == 0)
			PhoneBook.NEW();
		else if (str.compare(0, 7, "SEARCH", 0, 7) == 0)
			PhoneBook.SEARCH();
		else
			std::cout << "- ADD to create a new contact\n- SEARCH to see all existing contact\n- EXIT to exit (thx captain obvious)\n";
	}
	return(0);
}