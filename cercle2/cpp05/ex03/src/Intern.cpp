#include "../include/Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm	*Intern::PardonFormC(std::string target)
{
	return (new PardonForm(target));
}

AForm	*Intern::RobotomyFormC(std::string target)
{
	return (new RobotomyForm(target));
}

AForm	*Intern::ShrubberyFormC(std::string target)
{
	return (new ShrubberyForm(target));
}

AForm* Intern::makeForm(std::string type, std::string target)
{
	AForm	*(*funcArray[3])(std::string target) = {&PardonFormC, &RobotomyFormC, &ShrubberyFormC};
	std::string funcLevel[3] = {"Pardon", "Robotomy", "Shrubbery"};
	for (int i = 0; i < 3; i++)
	{
		if (funcLevel[i] == type)
		{
			std::cout << "An Intern have created a " << funcLevel[i] << " Form" << std::endl;
			return (funcArray[i](target));
		}
	}
	std::cout << "The form : " << type << " do not exist" << std::endl;
	return (0);
	
}