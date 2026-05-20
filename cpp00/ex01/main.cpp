#include <iostream>
#include "phonebook.hpp"
#include "contact.hpp"
using namespace std;


int main(void)
{
	phonebook PhoneBook;
	std::string str;
	cout << "- ADD to create a new contact\n- SEARCH to see all existing contact\n- EXIT to exit (thx captain obvious)\n";
	while (1)
	{
		cout << "Type your command : ";
		getline(cin >> ws, str);
		if (str.compare(0, 5, "EXIT", 0, 5) == 0)
			return (1);
		else if (str.compare(0, 4, "ADD", 0, 4) == 0)
			PhoneBook.NEW();
		else if (str.compare(0, 7, "SEARCH", 0, 7) == 0)
			PhoneBook.SEARCH();
		else
			cout << "- ADD to create a new contact\n- SEARCH to see all existing contact\n- EXIT to exit (thx captain obvious)\n";
	}
	return(0);
}