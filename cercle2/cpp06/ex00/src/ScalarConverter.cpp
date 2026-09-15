#include "../include/ScalarConverter.hpp"

int	isint(std::string str)
{
	int i = 0;
	if (!(str[i] == '+' || str[i] == '-' || isdigit(str[i])))
		return (0);
	i++;
	while (str[i++])
	{
		if (isdigit(str[i]) == 0 && str[i] != 0)
			return (0);
	}
	return (1);
}

int	isfloat(std::string str)
{
	int point = 0;
	int i = 0;
	if (!(str[i] == '+' || str[i] == '-' || isdigit(str[i])))
		return (0);
	while (str[i++])
	{
		if (str[i] == '.')
		{
			if (point != 0)
				return (0) ;
			else
			{
				i++;
				point++;
				if (isdigit(str[i]) == 0)
					return (0);
			}
		}
		if (isdigit(str[i]) == 0 && str[i] != 0)
		{
			if (str[i] == 'f' && str[i+1] == '\0')
				return (1);
			return (0);
		}
	}
	return(0);
}

int	isdouble(std::string str)
{
	int point = 0;
	int i = 0;
	if (!(str[i] == '+' || str[i] == '-' || isdigit(str[i])))
		return (0);
	while (str[i++])
	{
		if (str[i] == '.')
		{
			if (point != 0)
				return (0) ;
			else
			{
				i++;
				point++;
				if (isdigit(str[i]) == 0)
					return (0);
			}
		}
		if (isdigit(str[i]) == 0 && str[i] != 0)
			return (0);
	}
	if (point != 1)
		return(0);
	return (1);
}

void	ScalarConverter::convert(std::string str)
{
	double value = 0;
	if ((str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0))
		return ;
		//cas special
	if ((str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0))
		return ;
		//cas special v2
	if (str.length() == 1)
	{
		if (str[0] < 48 ||  str[0] > 57)
		{
			value = static_cast<double>(str[0]);
			return ;
		}
	}
	if (isint(str) == 1 || isfloat(str) == 1 || isdouble(str) == 1)
	{
		value = std::strtod(str.c_str(), NULL);
		return ;
	}
	else
	{
		std::cout << "invalid argument" << std::endl;
		return ;
	}
}


// 1. Pseudo-littéraux float  : "-inff", "+inff", "nanf"
// 2. Pseudo-littéraux double : "-inf",  "+inf",  "nan"
// 3. CHAR   : longueur == 1 ET le caractère n'est pas un chiffre
//             (optionnel : accepter aussi la forme "'c'" de longueur 3)
// 4. INT    : [+|-] suivi uniquement de chiffres, au moins un chiffre
// 5. FLOAT  : [+|-] chiffres '.' chiffres 'f'   → un seul '.', se termine par 'f',
//             au moins un chiffre, rien d'autre
// 6. DOUBLE : [+|-] chiffres '.' chiffres       → un seul '.', pas de 'f'
// 7. sinon  : littéral invalide → message d'erreur clair