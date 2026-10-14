#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> container;
	container.push_back(12);
	container.push_back(42);
	container.push_back(12434);
	container.push_back(67);
	container.push_back(0);
	container.push_back(8173);
	std::cout << easyfind(container, 42) << std::endl;
}