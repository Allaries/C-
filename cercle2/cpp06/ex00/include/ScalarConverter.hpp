#ifndef CONVERTER
# define CONVERTER
# include <cstdlib>
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