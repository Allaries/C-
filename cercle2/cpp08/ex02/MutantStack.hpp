#ifndef MUTANTSTACK
# define MUTANTSTACK

# include <iostream>
# include <stack>
# include <vector>
# include <list>

template<typename T>
class MutantStack : public std::stack<T, std::vector<T> >
{
public:
	typedef typename std::vector<T>::iterator iterator;
	iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }
	MutantStack();
	~MutantStack();
};


#include "MutantStack.tpp"
#endif