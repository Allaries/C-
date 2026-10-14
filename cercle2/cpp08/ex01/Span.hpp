#ifndef SPAN
# define SPAN

# include <algorithm>
# include <iostream>
# include <vector>

class Span
{
private:
	std::vector<int> container;
	unsigned int	N;
public:
	Span(unsigned int N);
	~Span();

	void	addNumber(int num);
	int		shortestSpan();
	int		longestSpan();

	class SpanOverflow : public std::exception
	{
		const char *what() const throw();
	};

	class NotEnoughNumber : public std::exception
	{
		const char *what() const throw();
	};
};




#endif