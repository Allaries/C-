#include <iostream>
#include "contact.hpp"
using namespace std;

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

int	is_num(std::string phone)
{
	int	i = 0;
	if (phone[0] == '+')
		i++;
	while (phone[i])
	{
		if (phone[i] < 48 || phone[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void    Contact::new_contact(void)
{
	int i = -1;
	i = 0;
	while (i < 5)
	{
		if (i == 0)
			cout << "Enter their first name : ";
		if (i == 1)
			cout << "Enter their last name : ";
		if (i == 2)
			cout << "Enter their nickname : ";
		if (i == 3)
			cout << "Enter their phone number : ";
		if (i == 4)
			cout << "Enter their most dark and twisted secret >:D : ";
		getline(cin >> ws, this->info[i]);
		if (i == 3)
		{
			if(is_num(this->info[3]) == 0)
			{
				cout << "that's not a phone number !\n";
			}
			else
				i++;
		}
		else
			i++;
	}
}

void	Contact::print_tab(void)
{
	int	i = 0;
	while (i < 5)
	{
		if (this->info[i].length() > 10)
		{
			cout << this->info[i].substr(0, 9);
			cout << ".";
		}
		else{
			cout << this->info[i];
			int space = 10 - this->info[i].length();
			while (space-- > 0)
				cout << " ";
		}
		cout << "|";
		i++;
	}
}

void	Contact::print_info(void)
{
	int	i = 0;
	while (i < 5)
	{
		if (i == 0)
			cout << "Their first name : ";
		if (i == 1)
			cout << "Their last name : ";
		if (i == 2)
			cout << "Their nickname : ";
		if (i == 3)
			cout << "Their phone number : ";
		if (i == 4)
			cout << "Their most dark and twisted secret >:D : ";
		cout << info[i];
		cout << "\n";
		i++;
	}
}