#include "include/Base.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 9; ++i)
    {
        Base* p = generate();
        std::cout << "ptr -> "; identify(p);
        std::cout << "ref -> "; identify(*p);
        delete p;
        std::cout << "---" << std::endl;
    }
}