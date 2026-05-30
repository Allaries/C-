#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		void				setType(std::string str);
		const std::string	&getType() const;
};

