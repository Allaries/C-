#include "easyfind.hpp"

template <typename T>
int	easyfind(T container, int needle)
{
	int i = container.size();
	int j = 0;
	while (j < i)
	{
		if (container[j] == needle)
			return (j);
		j++;
	}
	return (-1);
}