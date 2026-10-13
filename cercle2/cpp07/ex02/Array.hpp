#ifndef ARRAY
# define ARRAY

# include <iostream>
# include <exception>

template <typename T>
class Array
{
private:
	T *ptr;
	unsigned const int len;
public:
	Array();
	Array(unsigned int len);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	unsigned int size();
	T& operator[](unsigned int index);

	class InvalidIndex : public std::exception
	{
		const char *what() const throw();
	};
};


# include "Array.tpp"
#endif