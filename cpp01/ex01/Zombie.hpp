#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	setname(std::string name);
};


Zombie* zombieHorde(int N, std::string name);
Zombie*	newZombie(std::string name);
