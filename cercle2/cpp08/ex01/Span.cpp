#include "Span.hpp"

void	Span::addNumber(int num)
{
	if (this->container.size() >= this->N)
		throw (SpanOverflow());
	container.push_back(num);
}

int	Span::longestSpan()
{
	int min;
	int max;
	long unsigned int i = 1;
	
	if (this->container.size() < 2)
		throw (NotEnoughNumber());
	min = container[0];
	max = container[0];
	while (i < this->container.size())
	{
		if (container[i] < min)
			min = container[i];
		if (container[i] > max)
			max = container[i];
		i++;
	}
	return (max - min);
}

int	Span::shortestSpan()
{
	long unsigned int i = 1;
	if (this->container.size() < 2)
		throw (NotEnoughNumber());
	std::sort(container.begin(), container.end());
	int	span = container[i] - container[i-1];
	while (i < this->container.size())
	{
		if (span > container[i] - container[i-1])
			span = container[i] - container[i-1];
		i++;
	}
	return (span);
}

const char* Span::SpanOverflow::what() const throw()
{
	return ("You can't add more numbers");
}

const char* Span::NotEnoughNumber::what() const throw()
{
	return ("You need more number to use this function");
}

Span::Span(unsigned int N)
{
	this->N = N;
}

Span::~Span()
{
}