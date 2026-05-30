#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon		weapon;
public:
	HumanA(std::string name, std::string weapon);
	~HumanA();
	void	attack();
};

