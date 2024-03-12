#include "ScalarConverter.hpp"

void ScalarConverter::convert(char *input)
{
	char c;
	int	i;
	float f;
	double d;
	bool	is_decimal = false;
	bool	is_float = false;
	bool	is_digit = false;
	int strIndex = 0;
	
	if (input[1] == '\0')
	{
		if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z'))
			c = input[0];
			return(convertFromC(c, i, f, d));
	}
	while (input[strIndex])
	{
		if (std::isdigit(input[strIndex]) == 1)
			is_digit = true;
		if (input[strIndex] == '.')
			is_decimal = true;
		if (input[strIndex] == 'f')
			is_float = true;
		strIndex++;
	}
	if (is_float == true && is_digit == true)
	{
		f = std::atof(input);
		return (convertFromF(c, i, f, d));
	}
	else if (is_decimal == true && is_digit == true)
	{
		d = std::atof(input);
		return (convertFromD(c, i, f, d));
	}
	else if (is_digit == true)
	{
		i = std::atoi(input);
		return (convertFromI(c, i, f, d));
	}
	
	std::cout << "Input given is invalid, try another one!" << std::endl;
	return ;
}