#include <iostream>

//fonction test
template <typename T>
void show(const T &value)
{
	std::cout << value << std::endl;
}

//iter
template <typename T>
void	iter(T *tab, const int len, void (*func)(const T &))
{
	for (int i = 0; i < len; i++)
		func(tab[i]);
}

