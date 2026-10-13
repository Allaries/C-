#include "Array.hpp"

template<typename T>
Array<T>::Array() : len(0)
{
	this->ptr = NULL;
}

template<typename T>
Array<T>::Array(unsigned int len):len(len)
{
	this->ptr = new T[len];
	ptr[3] = 52;
}

template<typename T>
Array<T>::~Array()
{
	if (this->len != 0)
		delete[] this->ptr;
}

template<typename T>
const char* Array<T>::InvalidIndex::what() const throw()
{
	return ("invalid index");
}


template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	try
	{
		if (index >= this->len)
			throw InvalidIndex();
		return this->ptr[index];
	}
	catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
		return ();
    }
}