#include <iostream>
#include "phonebook.hpp"

int	string_atoi(std::string input)
{
	int	i = 0;
	int	sign = 1;
	long result = 0;
	if (input[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (input[i] >= 48 && input[i] <= 57)
	{
        result = result * 10 + (input[i] - '0');
        i++;
    }
	if (input[i] < 48 || input[i] > 57)
		return (-1);
	result *= sign;
	if (result >= 2147483648 || result <= -2147483649)
		return (-1);
	return (result);
}

void    phonebook::NEW(void)
{
	this->contact[this->index].new_contact();
	this->index++;
	if (this->index >= 8)
	{
		std::cout << "full";
		this->is_full = true;
		this->index = this->index % 8;
	}
}

void    phonebook::SEARCH(void)
{
	int	i = 0;
	int max;
	if (this->is_full == true)
		max = 8;
	else
		max = this->index;
	if (max == 0)
	{
		std::cout << "*No contact saved yet*\n";
		return ;
	}
	while (i < max)
	{
		std::cout << i;
		std::cout << ".    |";
		this->contact[i].print_tab();
		i++;
		std::cout << std::endl;
	}
	std::cout << "enter the number of the contact you are searching for : ";
	std::string input;
	std::getline(std::cin >> std::ws, input);
	i = string_atoi(input);
	if (i >= max || i < 0)
		std::cout << "invalid number\n";
	else
		this->contact[i].print_info();
}


phonebook::phonebook(void) : is_full(false), index(0)
{
}

phonebook::~phonebook()
{
}
