#ifndef CONVERTER
# define CONVERTER
# include <cstdlib>
# include <limits>
# include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
public:
	static void	convert(std::string str);
};


#endif