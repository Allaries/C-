#include "iter.hpp"

int	main(void)
{
	int array2[5] = {42, 36, 67, 1, 0};
	iter(array2, 5, show);
	std::string array[2] = {"Maitre", "Corbeau"};
	iter(array, 2, show);
	int array3[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	iter(array3, 15, show);
}