#ifndef WANIMALCLASS
# define WANIMALCLASS
# include <iostream>

class Wanimal
{
protected:
	std::string type;
public:
	Wanimal();
	Wanimal(const Wanimal &copy);
	virtual ~Wanimal();
	void	makeSound();
	void	getType();
	void	setType(std::string type);
};
#endif